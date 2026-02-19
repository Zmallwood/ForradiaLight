/*
 * Copyright 2026 Andreas Åkerberg
 * This code is licensed under MIT license (see LICENSE for details)
 */

#include "Player.hpp"
#include "Core/WorldStructure/World.hpp"
#include "Core/WorldStructure/WorldArea.hpp"
#include "Core/WorldStructure/Tile.hpp"
#include "Theme0/Configuration/Properties.hpp"

namespace Forradia
{
    Player::Player()
    {
        ApplyAuraToWorld();
    }

    void Player::MoveNorth()
    {
        if (m_position.y <= 0)
        {
            return;
        }

        m_position.y -= 1;

        ApplyAuraToWorld();
    }

    void Player::MoveEast()
    {
        if (m_position.x >= Properties::k_worldAreaSize.width - 1)
        {
            return;
        }

        m_position.x += 1;

        ApplyAuraToWorld();
    }

    void Player::MoveSouth()
    {
        if (m_position.y >= Properties::k_worldAreaSize.height - 1)
        {
            return;
        }

        m_position.y += 1;

        ApplyAuraToWorld();
    }

    void Player::MoveWest()
    {
        if (m_position.x <= 0)
        {
            return;
        }

        m_position.x -= 1;

        ApplyAuraToWorld();
    }

    void Player::AddExperience(int value)
    {
        m_experience += value;
    }

    void Player::ApplyAuraToWorld()
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

                AddExperience(darknessDelta);

                tile->SetDarknessLevel(newDarknessLevel);
            }
        }
    }
}