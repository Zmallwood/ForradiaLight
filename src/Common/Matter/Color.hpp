/*
 * Copyright 2026 Andreas Åkerberg
 * This code is licensed under MIT license (see LICENSE for details)
 */

#pragma once

namespace Forradia
{
    /**
     * Represents a color in the RGBA format.
     */
    class Color
    {
      public:
        SDL_Color ToSDLColor() const;

        float r{0.0f};
        float g{0.0f};
        float b{0.0f};
        float a{1.0f};
    };
}