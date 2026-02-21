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
#include "Theme0/Theme0Math/ExperienceMath.hpp"
#include "Core/GUICore/GUITextConsole.hpp"

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

        if (m_ticksStartMeditating > 0)
        {
            m_ticksStartMeditating = 0;

            _<GUITextConsole>().PrintLine("You stop meditating.");
        }

        m_auraStrength = std::max(m_auraStrength - 0.005f, 0.0f);

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

        if (m_ticksStartMeditating > 0)
        {
            m_ticksStartMeditating = 0;

            _<GUITextConsole>().PrintLine("You stop meditating.");
        }

        m_auraStrength = std::max(m_auraStrength - 0.005f, 0.0f);

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

        if (m_ticksStartMeditating > 0)
        {
            m_ticksStartMeditating = 0;

            _<GUITextConsole>().PrintLine("You stop meditating.");
        }

        m_auraStrength = std::max(m_auraStrength - 0.005f, 0.0f);

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

        if (m_ticksStartMeditating > 0)
        {
            m_ticksStartMeditating = 0;

            _<GUITextConsole>().PrintLine("You stop meditating.");
        }

        m_auraStrength = std::max(m_auraStrength - 0.005f, 0.0f);

        ApplyAuraToWorld();
    }

    void Player::AddExperience(int value)
    {
        auto levelBefore{CalculateCurrentLevel(m_experience)};

        m_experience += value;

        auto levelAfter{CalculateCurrentLevel(m_experience)};

        if (levelAfter > levelBefore)
        {
            _<GUITextConsole>().PrintLine("You have reached level " + std::to_string(levelAfter) +
                                          ".");
        }
    }

    bool Player::IsHungry() const
    {
        return m_hunger >= 0.9f;
    }

    bool Player::IsThirsty() const
    {
        return m_thirst >= 0.9f;
    }

    float Player::GetMovementSpeed() const
    {
        if (m_hunger >= 0.9f || m_thirst >= 0.9f)
        {
            return m_weakMovementSpeed;
        }

        return m_normalMovementSpeed;
    }

    void Player::ApplyAuraToWorld(bool affectPlayer)
    {
        if (m_auraStrength <= 0.00001f)
        {
            return;
        }

        auto worldArea{_<World>().GetCurrentWorldArea()};

        if (!worldArea)
        {
            throw std::runtime_error("Player: Current world area doesn't exist.");
        }

        auto maxAuraDistance{16};
        auto auraSize{GetAuraSize()};

        auto totalExpGain{0.0f};
        auto totalHungerGain{0.0f};
        auto totalThirstGain{0.0f};

        for (auto y = m_position.y - maxAuraDistance; y <= m_position.y + maxAuraDistance; y++)
        {
            for (auto x = m_position.x - maxAuraDistance; x <= m_position.x + maxAuraDistance; x++)
            {
                if (!worldArea->IsValidTile(x, y))
                {
                    continue;
                }

                auto tile{worldArea->GetTile(x, y)};

                auto dx{(x - m_position.x) / m_auraStrength};
                auto dy{(y - m_position.y) / m_auraStrength};

                auto distance{static_cast<int>(sqrt(dx * dx + dy * dy))};

                auto origDarknessLevel{tile->GetDarknessLevel()};

                auto newDarknessLevel{std::min(origDarknessLevel, distance / auraSize)};

                auto darknessDelta{origDarknessLevel - newDarknessLevel};

                totalExpGain += darknessDelta / 5.0f;
                totalHungerGain += 0.00001f;
                totalThirstGain += 0.000007f;

                tile->SetDarknessLevel(newDarknessLevel);
            }
        }

        if (affectPlayer)
        {
            AddExperience(totalExpGain);
            m_hunger = std::min(m_hunger + totalHungerGain, 1.0f);
            m_thirst = std::min(m_thirst + totalThirstGain, 1.0f);
        }
    }
}