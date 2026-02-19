/*
 * Copyright 2026 Andreas Åkerberg
 * This code is licensed under MIT license (see LICENSE for details)
 */

#include "WorldArea.hpp"
#include "Theme0/Configuration/Properties.hpp"
#include "Tile.hpp"

namespace Forradia
{
    WorldArea::WorldArea()
    {
        auto size{Properties::k_worldAreaSize};

        for (auto x = 0; x < size.width; x++)
        {
            m_tiles.push_back(std::vector<std::shared_ptr<Tile>>());

            for (auto y = 0; y < size.height; y++)
            {
                m_tiles.at(x).push_back(std::make_shared<Tile>());
            }
        }
    }

    Size WorldArea::GetSize() const
    {
        auto width{static_cast<int>(m_tiles.size())};
        auto height{0};

        if (width)
        {
            height = static_cast<int>(m_tiles.at(0).size());
        }

        return {width, height};
    }

    bool WorldArea::IsValidTile(int x, int y) const
    {
        auto size{GetSize()};

        return x >= 0 && x < size.width && y >= 0 && y < size.height;
    }

    std::shared_ptr<Tile> WorldArea::GetTile(int x, int y) const
    {
        if (!IsValidTile(x, y))
        {
            throw std::runtime_error("WorldArea: Requested tile is not valid.");
        }

        return m_tiles.at(x).at(y);
    }
}