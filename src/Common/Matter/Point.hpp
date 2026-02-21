/*
 * Copyright 2026 Andreas Åkerberg
 * This code is licensed under MIT license (see LICENSE for details)
 */

#pragma once

namespace Forradia
{
    /**
     * Represents a point in the 2D space with integer precision.
     */
    class Point
    {
      public:
        /**
         * Checks equality with another point.
         *
         * @param other The other point to check equality with.
         * @return True of equal, otherwise false.
         */
        bool operator==(const Point &other) const;

        int x{0}; ///< X dimension.
        int y{0}; ///< Y dimension.
    };
}
