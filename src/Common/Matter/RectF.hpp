/*
 * Copyright 2026 Andreas Åkerberg
 * This code is licensed under MIT license (see LICENSE for details)
 */

#pragma once

namespace Forradia
{
    class RectF
    {
      public:
        bool Contains(const PointF &point) const;

        float x{0.0f};
        float y{0.0f};
        float width{0.0f};
        float height{0.0f};
    };
}