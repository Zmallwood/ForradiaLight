/*
 * Copyright 2026 Andreas Åkerberg
 * This code is licensed under MIT license (see LICENSE for details)
 */

#include "Cursor.hpp"
#include "Core/Rendering/ImageRenderer.hpp"

namespace Forradia
{
    void Cursor::Initialize()
    {
        SDL_ShowCursor(SDL_DISABLE);
    }

    void Cursor::Render() const
    {
        auto mousePosition{GetMousePosition()};

        auto imageRenderer{_<ImageRenderer>()};

        auto cursorWidth{k_cursorWidth};

        auto cursorHeight{ConvertWidthToHeight(cursorWidth)};

        imageRenderer.DrawImage("CursorDefault", mousePosition.x - cursorWidth / 2, mousePosition.y - cursorHeight / 2, cursorWidth,
                                cursorHeight);
    }

    void Cursor::Cleanup() const
    {
        SDL_ShowCursor(SDL_ENABLE);
    }
}