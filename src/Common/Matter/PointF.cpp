/*
 * Copyright 2026 Andreas Åkerberg
 * This code is licensed under MIT license (see LICENSE for details)
 */

#include "PointF.hpp"

namespace Forradia
{
    void PointF::operator+=(const PointF &other)
    {
        x += other.x;
        y += other.y;
    }
}