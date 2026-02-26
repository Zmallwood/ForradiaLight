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

        auto GetTicksLastMove() const
        {
            return m_ticksLastMove;
        }

        void SetTicksLastMove(int value)
        {
            m_ticksLastMove = value;
        }

        auto GetMovementSpeed() const
        {
            return m_movementSpeed;
        }

      private:
        int m_type{0};               ///< Hash code of this creatures name.
        int m_ticksLastMove{0};      ///< Ticks since last move.
        float m_movementSpeed{1.0f}; ///< Movement speed.
    };
}
