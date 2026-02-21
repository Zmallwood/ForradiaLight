/*
 * Copyright 2026 Andreas Åkerberg
 * This code is licensed under MIT license (see LICENSE for details)
 */

#pragma once

namespace Forradia
{
    /**
     * Represents a size in the 2D space with floating point precision.
     */
    class SizeF
    {
      public:
        float width{0.0f};  ///< Width component.
        float height{0.0f}; ///< Height component.
    };
}
