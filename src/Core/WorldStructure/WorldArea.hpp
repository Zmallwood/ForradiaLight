/*
 * Copyright 2026 Andreas Åkerberg
 * This code is licensed under MIT license (see LICENSE for details)
 */

#pragma once

namespace Forradia
{
    class Tile;

    class WorldArea
    {
      public:
        WorldArea();

        Size GetSize() const;

        bool IsValidTile(int x, int y) const;

        std::shared_ptr<Tile> GetTile(int x, int y) const;

      private:
        std::vector<std::vector<std::shared_ptr<Tile>>> m_tiles;
    };
}