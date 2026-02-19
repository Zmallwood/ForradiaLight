/*
 * Copyright 2026 Andreas Åkerberg
 * This code is licensed under MIT license (see LICENSE for details)
 */

#include "UpdateSkillCasting.hpp"
#include "Core/Input/Keyboard/KeyboardInput.hpp"
#include "Core/CoreGameObjects/Player.hpp"
#include "Core/WorldStructure/World.hpp"
#include "Core/WorldStructure/WorldArea.hpp"
#include "Core/WorldStructure/Tile.hpp"

namespace Forradia
{
    void UpdateSkillCasting()
    {
        auto num1Pressed{_<KeyboardInput>().KeyIsPressedPickResult(SDLK_1)};

        auto now{SDL_GetTicks()};

        if (num1Pressed)
        {
            auto worldArea{_<World>().GetCurrentWorldArea()};

            auto playerPosition{_<Player>().GetPosition()};

            auto skillRadius{4};

            for (auto y = playerPosition.y - skillRadius; y <= playerPosition.y + skillRadius; y++)
            {
                for (auto x = playerPosition.x - skillRadius; x <= playerPosition.x + skillRadius;
                     x++)
                {
                    if (!worldArea->IsValidTile(x, y))
                    {
                        continue;
                    }

                    auto dx{x - playerPosition.x};
                    auto dy{y - playerPosition.y};

                    auto distance{static_cast<int>(sqrt(dx * dx + dy * dy))};

                    if (distance > skillRadius)
                    {
                        continue;
                    }

                    auto tile{worldArea->GetTile(x, y)};

                    auto origDarknessLevel{tile->GetDarknessLevel()};

                    auto newDarknessLevel{0};

                    auto darknessDelta{origDarknessLevel - newDarknessLevel};

                    tile->SetDarknessLevel(0);

                    _<Player>().AddExperience(darknessDelta);

                    tile->SetSkillNameHash(Hash("SkillLightArea"));

                    tile->SetTicksSkillCasted(now);
                }
            }
        }
    }
}