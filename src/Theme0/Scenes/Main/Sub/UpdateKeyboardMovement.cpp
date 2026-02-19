/*
 * Copyright 2026 Andreas Åkerberg
 * This code is licensed under MIT license (see LICENSE for details)
 */

#include "UpdateKeyboardMovement.hpp"
#include "Core/Input/Keyboard/KeyboardInput.hpp"
#include "Core/CoreGameObjects/Player.hpp"

namespace Forra
{
    void UpdateKeyboardMovement()
    {
        auto now{SDL_GetTicks()};

        auto upPressed{_<KeyboardInput>().KeyIsPressed(SDLK_UP)};
        auto downPressed{_<KeyboardInput>().KeyIsPressed(SDLK_DOWN)};
        auto leftPressed{_<KeyboardInput>().KeyIsPressed(SDLK_LEFT)};
        auto rightPressed{_<KeyboardInput>().KeyIsPressed(SDLK_RIGHT)};

        auto wPressed{_<KeyboardInput>().KeyIsPressed(SDLK_w)};
        auto aPressed{_<KeyboardInput>().KeyIsPressed(SDLK_a)};
        auto sPressed{_<KeyboardInput>().KeyIsPressed(SDLK_s)};
        auto dPressed{_<KeyboardInput>().KeyIsPressed(SDLK_d)};

        if (now > _<Player>().GetTicksLastMove() + InvertSpeed(_<Player>().GetMovementSpeed()) &&
            (upPressed || downPressed || leftPressed || rightPressed || wPressed || aPressed ||
             sPressed || dPressed))
        {
            _<Player>().SetDestinationCoordinate({-1, -1});

            if (upPressed || wPressed)
            {
                _<Player>().MoveNorth();
            }

            if (rightPressed || dPressed)
            {
                _<Player>().MoveEast();
            }

            if (downPressed || sPressed)
            {
                _<Player>().MoveSouth();
            }

            if (leftPressed || aPressed)
            {
                _<Player>().MoveWest();
            }

            _<Player>().SetTicksLastMove(now);
        }
    }
}