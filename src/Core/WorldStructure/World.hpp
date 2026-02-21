/*
 * Copyright 2026 Andreas Åkerberg
 * This code is licensed under MIT license (see LICENSE for details)
 */

#pragma once

namespace Forradia
{
    class WorldArea;

    /**
     * Represents the game world.
     */
    class World
    {
      public:
        World();

        auto GetCurrentWorldArea() const
        {
            return m_currentWorldArea;
        }

      private:
        std::shared_ptr<WorldArea> m_currentWorldArea;
    };
}