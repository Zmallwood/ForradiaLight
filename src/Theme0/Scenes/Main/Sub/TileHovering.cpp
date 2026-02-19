/*
 * Copyright 2026 Andreas Åkerberg
 * This code is licensed under MIT license (see LICENSE for details)
 */

#include "TileHovering.hpp"
#include "Theme0/Theme0Math/TileGridMath.hpp"
#include "Core/CoreGameObjects/Player.hpp"

namespace Forra
{
    void TileHovering::Update()
    {
        auto mousePosition{GetMousePosition()};

        auto tileGridSize{CalcTileGridSize()};

        auto tileSize{CalcTileSize()};

        auto tileX{static_cast<int>(mousePosition.x / tileSize.width + 0.5f)};
        auto tileY{static_cast<int>(mousePosition.y / tileSize.height + 0.5f)};

        auto playerPosition{_<Player>().GetPosition()};

        auto coordinateX{playerPosition.x - (tileGridSize.width - 1) / 2 + tileX};
        auto coordinateY{playerPosition.y - (tileGridSize.height - 1) / 2 + tileY};

        m_hoveredCoordinate = {coordinateX, coordinateY};
    }
}