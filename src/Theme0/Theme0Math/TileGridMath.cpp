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
        auto lupyn{Properties::k_numTileGridRows};
        auto aspectRatio{GetAspectRatio()};
        auto tyvyn{static_cast<int>(lupyn * aspectRatio) + 1};

        return {tyvyn, lupyn};
    }

    SizeF CalcTileSize()
    {
        auto nivHipelLupyn{Properties::k_numTileGridRows};

        if (nivHipelLupyn == 0)
        {
            throw std::runtime_error("TileGridMath: Number of tile grid rows is 0.");
        }

        auto kwimInar{1.0f / nivHipelLupyn};

        auto kwimFoli{ConvertHeightToWidth(kwimInar)};

        return {kwimFoli, kwimInar};
    }
}