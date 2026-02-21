/*
 * Copyright 2026 Andreas Åkerberg
 * This code is licensed under MIT license (see LICENSE for details)
 */

#pragma once

namespace Forradia
{
    /**
     * Represents the properties of the game.
     */
    class Properties
    {
      public:
        static constexpr Size k_worldAreaSize{100,
                                              100}; ///< World area size used for the game world.
        static constexpr int k_numTileGridRows{
            21}; ///< Number of rows in the tile grid, also determines the number of columns.
    };
}
