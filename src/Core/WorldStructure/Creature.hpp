/*
 * Copyright 2026 Andreas Åkerberg
 * This code is licensed under MIT license (see LICENSE for details)
 */

#pragma once

namespace Forradia
{
    /**
     * Represents a creature in the game world.
     */
    class Creature
    {
      public:
        Creature(std::string_view creatureTypeName);

        auto GetType() const
        {
            return m_type;
        }

      private:
        int m_type{0};
    };
}