/*
 * Copyright 2026 Andreas Åkerberg
 * This code is licensed under MIT license (see LICENSE for details)
 */

#pragma once

namespace Forradia
{
    /**
     * Represents the image renderer, used to render images to the canvas.
     */
    class ImageRenderer
    {
      public:
        void DrawImage(int imageNameHash, float x, float y, float width, float height);

        void DrawImage(std::string_view imageName, float x, float y, float width, float height);
    };
}