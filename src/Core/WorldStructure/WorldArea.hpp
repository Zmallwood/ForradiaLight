/*
 * Copyright 2026 Andreas Åkerberg
 * This code is licensed under MIT license (see LICENSE for details)
 */

#pragma once

namespace Forradia
{
    class Tile;
    class Creature;

    /**
     * Represents a tile grid area of the game world.
     */
    class WorldArea
    {
      public:
        WorldArea();

        Size GetSize() const;

        bool IsValidTile(int x, int y) const;

        std::shared_ptr<Tile> GetTile(int x, int y) const;

        auto &GetCreaturesMirrorRef()
        {
            return m_creaturesMirror;
        }

      private:
        std::vector<std::vector<std::shared_ptr<Tile>>>
            m_tiles; ///< 2D tile grid of this world area.
        std::unordered_map<std::shared_ptr<Creature>, Point> m_creaturesMirror;
    };
}
