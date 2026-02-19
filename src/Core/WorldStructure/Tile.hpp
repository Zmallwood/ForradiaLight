/*
 * Copyright 2026 Andreas Åkerberg
 * This code is licensed under MIT license (see LICENSE for details)
 */

#pragma once

namespace Forra
{
    class ObjectsStack;

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

      private:
        int m_ground{0};
        std::shared_ptr<ObjectsStack> m_objectsStack;
        int m_darknessLevel{6};
    };
}