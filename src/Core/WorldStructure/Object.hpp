/*
 * Copyright 2026 Andreas Åkerberg
 * This code is licensed under MIT license (see LICENSE for details)
 */

#pragma once

namespace Forradia
{
    /**
     * Represents an object in the game world.
     */
    class Object
    {
      public:
        Object(int type);

        auto GetType() const
        {
            return m_type;
        }

      private:
        int m_type{0}; ///< Hash code of the name of this objects type.
    };
}
