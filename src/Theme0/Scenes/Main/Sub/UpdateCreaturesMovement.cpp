/*
 * Copyright 2026 Andreas Åkerberg
 * This code is licensed under MIT license (see LICENSE for details)
 */

#include "UpdateCreaturesMovement.hpp"
#include "Core/WorldStructure/World.hpp"
#include "Core/WorldStructure/WorldArea.hpp"
#include "Core/WorldStructure/Creature.hpp"
#include "Core/WorldStructure/Tile.hpp"

namespace Forradia
{
    void UpdateCreaturesMovement()
    {
        auto now{SDL_GetTicks()};

        auto worldArea{_<World>().GetCurrentWorldArea()};

        auto &creatures{worldArea->GetCreaturesMirrorRef()};

        for (auto it = creatures.begin(); it != creatures.end();)
        {
            auto creature{it->first};
            auto position{it->second};

            if (now > creature->GetTicksLastMove() + InvertSpeed(creature->GetMovementSpeed()))
            {
                auto dx{rand() % 2 - rand() % 2};
                auto dy{rand() % 2 - rand() % 2};

                auto newPosition{position + Point{dx, dy}};

                if (worldArea->IsValidTile(newPosition.x, newPosition.y))
                {
                    auto oldTile{worldArea->GetTile(position.x, position.y)};
                    auto newTile{worldArea->GetTile(newPosition.x, newPosition.y)};

                    if (newTile->GetGround() != Hash("GroundWater") &&
                        newTile->GetCreature() == nullptr)
                    {
                        oldTile->SetCreature(nullptr);
                        newTile->SetCreature(creature);

                        creatures.erase(it++);
                        creatures[creature] = newPosition;

                        creature->SetTicksLastMove(now);

                        continue;
                    }
                }

                creature->SetTicksLastMove(now);
            }

            ++it;
        }
    }
}