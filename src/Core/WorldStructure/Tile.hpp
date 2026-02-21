/*
 * Copyright 2026 Andreas Åkerberg
 * This code is licensed under MIT license (see LICENSE for details)
 */

#pragma once

namespace Forradia
{
    class ObjectsStack;
    class Creature;

    /**
     * Represents a tile in the game world.
     */
    class Tile
    {
      public:
        Tile();

        auto GetGround() const
        {
            return m_ground;
        }

        void SetGround(std::string_view value)
        {
            m_ground = Hash(value);
        }

        auto GetObjectsStack() const
        {
            return m_objectsStack;
        }

        auto GetDarknessLevel() const
        {
            return m_darknessLevel;
        }

        void SetDarknessLevel(int value)
        {
            m_darknessLevel = value;
        }

        auto GetCreature() const
        {
            return m_creature;
        }

        void SetCreature(std::shared_ptr<Creature> value)
        {
            m_creature = value;
        }

        auto GetSkillNameHash() const
        {
            return m_skillNameHash;
        }

        void SetSkillNameHash(int value)
        {
            m_skillNameHash = value;
        }

        auto GetTicksSkillCasted() const
        {
            return m_ticksSkillCasted;
        }

        void SetTicksSkillCasted(int value)
        {
            m_ticksSkillCasted = value;
        }

      private:
        int m_ground{0}; ///< Hash code of the ground type of this tile.
        std::shared_ptr<ObjectsStack>
            m_objectsStack;     ///< Stack containing the objects for this tile.
        int m_darknessLevel{6}; ///< The current darkness level of this tile.
        std::shared_ptr<Creature>
            m_creature;         ///< The creature located on this tile, or nullptr if there is none.
        int m_skillNameHash{0}; ///< The hash code of the name of the skill last casted on this
                                ///< tile, or 0 if there is none.
        int m_ticksSkillCasted{0}; ///< The ticks when the last skill was casted on this tile.
    };
}
