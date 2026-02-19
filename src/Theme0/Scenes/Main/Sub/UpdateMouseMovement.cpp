/*
 * Copyright 2026 Andreas Åkerberg
 * This code is licensed under MIT license (see LICENSE for details)
 */

#include "UpdateMouseMovement.hpp"
#include "Core/CoreGameObjects/Player.hpp"
#include "Theme0/Scenes/Main/Sub/TileHovering.hpp"
#include "Core/Input/Mouse/MouseInput.hpp"

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
            auto dx{destinationCoordinate.x - currentCoordinate.x};
            auto dy{destinationCoordinate.y - currentCoordinate.y};

            if (dy < 0)
            {
                _<Player>().MoveNorth();
            }

            if (dx > 0)
            {
                _<Player>().MoveEast();
            }

            if (dy > 0)
            {
                _<Player>().MoveSouth();
            }

            if (dx < 0)
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