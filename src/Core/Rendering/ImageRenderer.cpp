/*
 * Copyright 2026 Andreas Åkerberg
 * This code is licensed under MIT license (see LICENSE for details)
 */

#include "ImageRenderer.hpp"
#include "Core/SDLDevice.hpp"
#include "Core/Assets/ImageBank.hpp"

namespace Forra
{
    void ImageRenderer::DrawImage(int imageNameHash, float x, float y, float width, float height)
    {
        auto canvasSize{GetCanvasSize()};

        auto renderer{_<SDLDevice>().GetRenderer()};

        if (!renderer)
        {
            throw std::runtime_error("ImageRenderer: Renderer doesn't exist.");
        }

        auto texture{_<ImageBank>().GetImage(imageNameHash)};

        if (!texture)
        {
            throw std::runtime_error("ImageRenderer: Requested image not found.");
        }

        SDL_Rect destination;

        destination.x = x * canvasSize.width;
        destination.y = y * canvasSize.height;
        destination.w = width * canvasSize.width;
        destination.h = height * canvasSize.height;

        SDL_RenderCopy(renderer.get(), texture.get(), nullptr, &destination);
    }

    void ImageRenderer::DrawImage(std::string_view imageName, float x, float y, float width,
                                  float height)
    {
        DrawImage(Hash(imageName), x, y, width, height);
    }
}