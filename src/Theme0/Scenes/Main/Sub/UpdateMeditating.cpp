/*
 * Copyright 2026 Andreas Åkerberg
 * This code is licensed under MIT license (see LICENSE for details)
 */

#include "UpdateMeditating.hpp"
#include "Core/Input/Keyboard/KeyboardInput.hpp"
#include "Core/CoreGameObjects/Player.hpp"
#include "Core/GUICore/GUITextConsole.hpp"

namespace Forradia
{
    void UpdateMeditating()
    {
        auto now{SDL_GetTicks()};

        auto mPressed{_<KeyboardInput>().KeyIsPressedPickResult(SDLK_m)};

        if (mPressed)
        {
            _<Player>().ToggleMeditating();
        }

        if (_<Player>().GetTicksStartMeditating() > 0)
        {
            if (now > _<Player>().GetTicksLastMeditationUpdate() + 1000)
            {
                _<Player>().SetTicksLastMeditationUpdate(now);

                _<Player>().SetAuraStrength(_<Player>().GetAuraStrength() + 0.01f);

                _<GUITextConsole>().PrintLine("You are meditating. Aura strength: " +
                                              std::to_string(_<Player>().GetAuraStrength()));

                _<Player>().ApplyAuraToWorld(false);
            }
        }
    }
}