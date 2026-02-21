/*
 * Copyright 2026 Andreas Åkerberg
 * This code is licensed under MIT license (see LICENSE for details)
 */

#pragma once

namespace Forradia
{
    /**
     * Represents the player character in the game.
     */
    class Player
    {
      public:
        /**
         * Initializes the played.
         */
        void Initialize();

        /**
         * Move the player north in the game world.
         */
        void MoveNorth();

        /**
         * Move the player east in the game world.
         */
        void MoveEast();

        /**
         * Move the player south in the game world.
         */
        void MoveSouth();

        /**
         * Move the player west in the game world.
         */
        void MoveWest();

        /**
         * Add an amount to the players experience.
         *
         * @param value Amount of experience to add.
         */
        void AddExperience(int value);

        /**
         * Gets the IsHungry-state.
         *
         * @return True if is hungry, otherwise false.
         */
        bool IsHungry() const;

        /**
         * Gets the IsThirsty-state.
         *
         * @return True if is thirsty, otherwise false.
         */
        bool IsThirsty() const;

        /**
         * Gets the movement speed, which can be either normal or weakened.
         *
         * @return The movement speed.
         */
        float GetMovementSpeed() const;

        /**
         * Apply the players aura to the world.
         *
         * @param affectPlayer Decides if the players experience, hunger, and thirst values
         * should be affect by this function when called.
         */
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
        /**
         * Makes sure the player is located on a suitable location, i.e. one that is not water.
         */
        void MakeIsOnSuitableLocation();

        Point m_position{50, 50};              ///< Position in the world area.
        int m_ticksLastMove{0};                ///< Ticks since last move in the game world.
        float m_normalMovementSpeed{3.5f};     ///< Movement speed when not in weakened state.
        float m_weakMovementSpeed{1.0f};       ///< Movement speed in weakened state.
        int m_auraSize{2};                     ///< Size of the aura.
        Point m_destinationCoordinate{-1, -1}; ///< Destination coordinate for movement.
        int m_experience{0};                   ///< Experience points.
        std::string m_name{"Unnamed Player"};  ///< Name.
        float m_hunger{0.0f};                  ///< Hunger value.
        float m_thirst{0.0f};                  ///< Thirst value.
        float m_auraStrength{0.2f};            ///< Strength of the aura.
        int m_ticksStartMeditating{0};         ///< Ticks when starting to meditate.
        int m_ticksLastMeditationUpdate{0};    ///< Ticks since last meditation update.
    };
}
