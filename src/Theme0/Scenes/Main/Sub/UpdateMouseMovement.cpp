/*
 * Copyright 2026 Andreas Åkerberg
 * This code is licensed under MIT license (see LICENSE for details)
 */

#include "UpdateMouseMovement.hpp"
#include "Core/CoreGameObjects/Player.hpp"
#include "Theme0/Scenes/Main/Sub/TileHovering.hpp"
#include "Core/Input/Mouse/MouseInput.hpp"
#include "Core/GUICore/GUITextConsole.hpp"

namespace Forradia
{
    void UpdateMouseMovement()
    {
        auto hoveredCoordinate{_<TileHovering>().GetHoveredCoordinate()};

        if (hoveredCoordinate.x == -1 || hoveredCoordinate.y == -1)
        {
            return;
        }

        if (_<MouseInput>().GetLeftButton()->IsPressedPickResult())
        {
            _<Player>().SetDestinationCoordinate(hoveredCoordinate);
        }

        auto destinationCoordinate{_<Player>().GetDestinationCoordinate()};

        if (destinationCoordinate.x == -1 || destinationCoordinate.y == -1)
        {
            return;
        }

        auto currentCoordinate{_<Player>().GetPosition()};

        auto now{SDL_GetTicks()};

        if (now > _<Player>().GetTicksLastMove() + InvertSpeed(_<Player>().GetMovementSpeed()))
        {
            if (_<Player>().IsHungry())
            {
                _<GUITextConsole>().PrintLine("You are hungry and are moving slower.");
            }
            else if (_<Player>().IsThirsty())
            {
                _<GUITextConsole>().PrintLine("You are thirsty and are moving slower.");
            }

            auto dx{destinationCoordinate.x - currentCoordinate.x};
            auto dy{destinationCoordinate.y - currentCoordinate.y};

            if (dx > 0 && dy < 0)
            {
                _<Player>().MoveNorthEast();
            }
            else if (dx > 0 && dy > 0)
            {
                _<Player>().MoveSouthEast();
            }
            else if (dx < 0 && dy > 0)
            {
                _<Player>().MoveSouthWest();
            }
            else if (dx < 0 && dy < 0)
            {
                _<Player>().MoveNorthWest();
            }
            else if (dy < 0)
            {
                _<Player>().MoveNorth();
            }
            else if (dx > 0)
            {
                _<Player>().MoveEast();
            }
            else if (dy > 0)
            {
                _<Player>().MoveSouth();
            }
            else if (dx < 0)
            {
                _<Player>().MoveWest();
            }

            if (_<Player>().GetPosition() == destinationCoordinate)
            {
                _<Player>().SetDestinationCoordinate({-1, -1});
            }

            _<Player>().SetTicksLastMove(now);
        }
    }
}