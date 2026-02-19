/*
 * Copyright 2026 Andreas Åkerberg
 * This code is licensed under MIT license (see LICENSE for details)
 */

#include "Point.hpp"

namespace Forra
{
    bool Point::operator==(const Point &other) const
    {
        return x == other.x && y == other.y;
    }
}