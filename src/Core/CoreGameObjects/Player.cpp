/*
 * Copyright 2026 Andreas Åkerberg
 * This code is licensed under MIT license (see LICENSE for details)
 */

#include "Player.hpp"
#include "Core/WorldStructure/World.hpp"
#include "Core/WorldStructure/WorldArea.hpp"
#include "Core/WorldStructure/Tile.hpp"
#include "Core/WorldStructure/ObjectsStack.hpp"
#include "Theme0/Configuration/Properties.hpp"

namespace Forradia
{
    void Player::Initialize()
    {
        MakeIsOnSuitableLocation();

        m_experience = 0;

        ApplyAuraToWorld(false);
    }

    void Player::MakeIsOnSuitableLocation()
    {
        auto worldArea{_<World>().GetCurrentWorldArea()};

        if (!worldArea)
        {
            throw std::runtime_error("Player: Current world area doesn't exist.");
        }

        auto worldAreaSize{worldArea->GetSize()};

        auto tile{worldArea->GetTile(m_position.x, m_position.y)};

        while (tile->GetGround() == Hash("GroundWater"))
        {
            m_position.x = rand() % worldAreaSize.width;
            m_position.y = rand() % worldAreaSize.height;

            tile = worldArea->GetTile(m_position.x, m_position.y);
        }
    }

    void Player::MoveNorth()
    {
        if (m_position.y <= 0)
        {
            return;
        }

        Point newPosition{m_position.x, m_position.y - 1};

        auto worldArea{_<World>().GetCurrentWorldArea()};

        if (!worldArea)
        {
            throw std::runtime_error("Player: Current world area doesn't exist.");
        }

        auto tile{worldArea->GetTile(newPosition.x, newPosition.y)};

        auto objectsStack{tile->GetObjectsStack()};

        if (objectsStack)
        {
            if (objectsStack->HasObjectOfType("ObjectTree1") ||
                objectsStack->HasObjectOfType("ObjectTree2") ||
                objectsStack->HasObjectOfType("ObjectBush1") ||
                objectsStack->HasObjectOfType("ObjectStoneBoulder"))
            {
                return;
            }
        }

        if (tile->GetGround() == Hash("GroundWater"))
        {
            return;
        }

        m_position = newPosition;

        ApplyAuraToWorld();
    }

    void Player::MoveEast()
    {
        if (m_position.x >= Properties::k_worldAreaSize.width - 1)
        {
            return;
        }

        Point newPosition{m_position.x + 1, m_position.y};

        auto worldArea{_<World>().GetCurrentWorldArea()};

        if (!worldArea)
        {
            throw std::runtime_error("Player: Current world area doesn't exist.");
        }

        auto tile{worldArea->GetTile(newPosition.x, newPosition.y)};

        auto objectsStack{tile->GetObjectsStack()};

        if (objectsStack)
        {
            if (objectsStack->HasObjectOfType("ObjectTree1") ||
                objectsStack->HasObjectOfType("ObjectTree2") ||
                objectsStack->HasObjectOfType("ObjectBush1") ||
                objectsStack->HasObjectOfType("ObjectStoneBoulder"))
            {
                return;
            }
        }

        if (tile->GetGround() == Hash("GroundWater"))
        {
            return;
        }

        m_position = newPosition;

        ApplyAuraToWorld();
    }

    void Player::MoveSouth()
    {
        if (m_position.y >= Properties::k_worldAreaSize.height - 1)
        {
            return;
        }

        Point newPosition{m_position.x, m_position.y + 1};

        auto worldArea{_<World>().GetCurrentWorldArea()};

        if (!worldArea)
        {
            throw std::runtime_error("Player: Current world area doesn't exist.");
        }

        auto tile{worldArea->GetTile(newPosition.x, newPosition.y)};

        auto objectsStack{tile->GetObjectsStack()};

        if (objectsStack)
        {
            if (objectsStack->HasObjectOfType("ObjectTree1") ||
                objectsStack->HasObjectOfType("ObjectTree2") ||
                objectsStack->HasObjectOfType("ObjectBush1") ||
                objectsStack->HasObjectOfType("ObjectStoneBoulder"))
            {
                return;
            }
        }

        if (tile->GetGround() == Hash("GroundWater"))
        {
            return;
        }

        m_position = newPosition;

        ApplyAuraToWorld();
    }

    void Player::MoveWest()
    {
        if (m_position.x <= 0)
        {
            return;
        }

        Point newPosition{m_position.x - 1, m_position.y};

        auto worldArea{_<World>().GetCurrentWorldArea()};

        if (!worldArea)
        {
            throw std::runtime_error("Player: Current world area doesn't exist.");
        }

        auto tile{worldArea->GetTile(newPosition.x, newPosition.y)};

        auto objectsStack{tile->GetObjectsStack()};

        if (objectsStack)
        {
            if (objectsStack->HasObjectOfType("ObjectTree1") ||
                objectsStack->HasObjectOfType("ObjectTree2") ||
                objectsStack->HasObjectOfType("ObjectBush1") ||
                objectsStack->HasObjectOfType("ObjectStoneBoulder"))
            {
                return;
            }
        }

        if (tile->GetGround() == Hash("GroundWater"))
        {
            return;
        }

        m_position = newPosition;

        ApplyAuraToWorld();
    }

    void Player::AddExperience(int value)
    {
        m_experience += value;
    }

    void Player::ApplyAuraToWorld(bool affectPlayer)
    {
        auto worldArea{_<World>().GetCurrentWorldArea()};

        if (!worldArea)
        {
            throw std::runtime_error("Player: Current world area doesn't exist.");
        }

        auto maxAuraDistance{16};
        auto auraSize{GetAuraSize()};

        for (auto y = m_position.y - maxAuraDistance; y <= m_position.y + maxAuraDistance; y++)
        {
            for (auto x = m_position.x - maxAuraDistance; x <= m_position.x + maxAuraDistance; x++)
            {
                if (!worldArea->IsValidTile(x, y))
                {
                    continue;
                }

                auto tile{worldArea->GetTile(x, y)};

                auto dx{x - m_position.x};
                auto dy{y - m_position.y};

                auto distance{static_cast<int>(sqrt(dx * dx + dy * dy))};

                auto origDarknessLevel{tile->GetDarknessLevel()};

                auto newDarknessLevel{std::min(origDarknessLevel, distance / auraSize)};

                auto darknessDelta{origDarknessLevel - newDarknessLevel};

                if (affectPlayer)
                {
                    AddExperience(darknessDelta);

                    m_hunger = std::min(m_hunger + 0.00001f, 1.0f);

                    m_thirst = std::min(m_thirst + 0.000007f, 1.0f);
                }

                tile->SetDarknessLevel(newDarknessLevel);
            }
        }
    }
}