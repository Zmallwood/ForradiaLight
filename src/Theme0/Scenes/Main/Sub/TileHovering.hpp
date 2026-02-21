/*
 * Copyright 2026 Andreas Åkerberg
 * This code is licensed under MIT license (see LICENSE for details)
 */

#pragma once

namespace Forradia
{
    /**
     * Represents the tile hovering, used to track the tile that the player is hovering over.
     */
    class TileHovering
    {
      public:
        void Update();

        auto GetHoveredCoordinate() const
        {
            return m_hoveredCoordinate;
        }

      private:
        Point m_hoveredCoordinate{
            -1, -1}; ///< Coordinate of the tile, that is currently hovered with the mouse.
    };
}
