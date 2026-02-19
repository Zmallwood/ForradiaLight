/*
 * Copyright 2026 Andreas Åkerberg
 * This code is licensed under MIT license (see LICENSE for details)
 */

#pragma once

namespace Forradia
{
    class Player
    {
      public:
        Player();

        void MoveNorth();

        void MoveEast();

        void MoveSouth();

        void MoveWest();

        void AddExperience(int value);

        auto GetPosition() const
        {
            return m_position;
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

        auto GetAuraSize() const
        {
            return m_auraSize;
        }

        auto GetDestinationCoordinate() const
        {
            return m_destinationCoordinate;
        }

        void SetDestinationCoordinate(Point value)
        {
            m_destinationCoordinate = value;
        }

        auto GetExperience() const
        {
            return m_experience;
        }

      private:
        void ApplyAuraToWorld();

        Point m_position{50, 50};
        int m_ticksLastMove{0};
        float m_movementSpeed{4.5f};
        int m_auraSize{2};
        Point m_destinationCoordinate{-1, -1};
        int m_experience{0};
    };
}