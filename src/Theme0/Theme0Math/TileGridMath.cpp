/*
 * Copyright 2026 Andreas Åkerberg
 * This code is licensed under MIT license (see LICENSE for details)
 */

#include "TileGridMath.hpp"
#include "Theme0/Configuration/Properties.hpp"

namespace Forradia
{
    Size CalcTileGridSize()
    {
        auto numTileGridRows{Properties::k_numTileGridRows};
        auto aspectRatio{GetAspectRatio()};
        auto numTileGridColumns{static_cast<int>(numTileGridRows * aspectRatio) + 1};

        return {numTileGridColumns, numTileGridRows};
    }

    SizeF CalcTileSize()
    {
        auto numTileGridRows{Properties::k_numTileGridRows};

        if (numTileGridRows == 0)
        {
            throw std::runtime_error("TileGridMath: Number of tile grid rows is 0.");
        }

        auto tileHeigt{1.0f / numTileGridRows};

        auto tileWidth{ConvertHeightToWidth(tileHeigt)};

        return {tileWidth, tileHeigt};
    }
}