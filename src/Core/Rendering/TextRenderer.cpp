/*
 * Copyright 2026 Andreas Åkerberg
 * This code is licensed under MIT license (see LICENSE for details)
 */

#include "TextRenderer.hpp"
#include "Core/SDLDevice.hpp"

namespace Forradia
{
    void TextRenderer::Initialize()
    {
        TTF_Init();

        AddFont(FontSizes::_20);
        AddFont(FontSizes::_26);
    }

    void TextRenderer::AddFont(FontSizes fontSize)
    {
        auto absFontPath{std::string(SDL_GetBasePath()) + k_defaultFontPath};
        auto fontPathUnixStyle{Replace(absFontPath, '\\', '/')};

        auto fontSizeN{static_cast<int>(fontSize)};

        auto newFont{std::shared_ptr<TTF_Font>(TTF_OpenFont(fontPathUnixStyle.c_str(), fontSizeN),
                                               SDLDeleter())};

        m_fonts.insert({fontSize, newFont});
    }

    void TextRenderer::DrawString(std::string_view text, FontSizes fontSize, float x, float y,
                                  Color color)
    {
        auto font{m_fonts[fontSize]};

        auto sdlColor{color.ToSDLColor()};

        auto surface{std::shared_ptr<SDL_Surface>(
            TTF_RenderText_Solid(font.get(), text.data(), sdlColor), SDLDeleter())};

        auto texture{std::shared_ptr<SDL_Texture>(
            SDL_CreateTextureFromSurface(_<SDLDevice>().GetRenderer().get(), surface.get()),
            SDLDeleter())};

        auto canvasSize{GetCanvasSize()};

        auto position{PointF{x, y}};

        SDL_Rect rect{static_cast<int>(position.x * canvasSize.width),
                      static_cast<int>(position.y * canvasSize.height), surface->w, surface->h};

        SDL_RenderCopy(_<SDLDevice>().GetRenderer().get(), texture.get(), nullptr, &rect);
    }
}