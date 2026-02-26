/*
 * Copyright 2026 Andreas Åkerberg
 * This code is licensed under MIT license (see LICENSE for details)
 */

#include "RectF.hpp"

namespace Forradia
{
    bool RectF::Contains(const PointF &point) const
    {
        return point.x >= x && point.x <= x + width && point.y >= y && point.y <= y + height;
    }
}