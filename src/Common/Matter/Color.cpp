/*
 * Copyright 2026 Andreas Åkerberg
 * This code is licensed under MIT license (see LICENSE for details)
 */

#include "Color.hpp"

namespace Forradia
{
    SDL_Color Color::ToSDLColor() const
    {
        return SDL_Color{static_cast<Uint8>(r * 255), static_cast<Uint8>(g * 255),
                         static_cast<Uint8>(b * 255), static_cast<Uint8>(a * 255)};
    }
}