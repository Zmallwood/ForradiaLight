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
        bool operator==(const Point &other) const;

        int x{0};
        int y{0};
    };
}