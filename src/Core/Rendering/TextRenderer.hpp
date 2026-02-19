/*
 * Copyright 2026 Andreas Åkerberg
 * This code is licensed under MIT license (see LICENSE for details)
 */

#pragma once

#include "FontSizes.hpp"

namespace Forradia
{
    class TextRenderer
    {
      public:
        void Initialize();

        void DrawString(std::string_view text, FontSizes fontSize, float x, float y,
                        Color color = Palette::Wheat);

      private:
        void AddFont(FontSizes fontSize);

        const std::string k_defaultFontPath{"./resources/fonts/PixeloidSans.ttf"};
        std::unordered_map<FontSizes, std::shared_ptr<TTF_Font>> m_fonts;
    };
}