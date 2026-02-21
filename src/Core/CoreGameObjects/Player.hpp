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
        void Initialize();

        void MoveNorth();

        void MoveEast();

        void MoveSouth();

        void MoveWest();

        void AddExperience(int value);

        bool IsHungry() const;

        bool IsThirsty() const;

        float GetMovementSpeed() const;

        void ApplyAuraToWorld(bool affectPlayer = true);

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

        auto GetName() const
        {
            return m_name;
        }

        auto GetHunger() const
        {
            return m_hunger;
        }

        auto GetThirst() const
        {
            return m_thirst;
        }

        auto GetWeakMovementSpeed() const
        {
            return m_weakMovementSpeed;
        }

        auto GetTicksStartMeditating() const
        {
            return m_ticksStartMeditating;
        }

        void SetTicksStartMeditating(int value)
        {
            m_ticksStartMeditating = value;
        }

        auto GetTicksLastMeditationUpdate() const
        {
            return m_ticksLastMeditationUpdate;
        }

        void SetTicksLastMeditationUpdate(int value)
        {
            m_ticksLastMeditationUpdate = value;
        }

        auto GetAuraStrength() const
        {
            return m_auraStrength;
        }

        void SetAuraStrength(float value)
        {
            m_auraStrength = value;
        }

      private:
        void MakeIsOnSuitableLocation();

        Point m_position{50, 50};
        int m_ticksLastMove{0};
        float m_normalMovementSpeed{3.5f};
        float m_weakMovementSpeed{1.0f};
        int m_auraSize{2};
        Point m_destinationCoordinate{-1, -1};
        int m_experience{0};
        std::string m_name{"Unnamed Player"};
        float m_hunger{0.0f};
        float m_thirst{0.0f};
        float m_auraStrength{0.2f};
        int m_ticksStartMeditating{0};
        int m_ticksLastMeditationUpdate{0};
    };
}