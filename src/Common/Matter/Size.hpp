/*
 * Copyright 2026 Andreas Åkerberg
 * This code is licensed under MIT license (see LICENSE for details)
 */

#pragma once

namespace Forradia
{
    /**
     * Represents a size in the 2D space with integer precision.
     */
    class Size
    {
      public:
        int width{0};  ///< Width component.
        int height{0}; ///< Height component.
    };
}
