/*
 * Copyright 2026 Andreas Åkerberg
 * This code is licensed under MIT license (see LICENSE for details)
 */

#include "Utilities.hpp"
#include "Core/SDLDevice.hpp"

namespace Forradia
{
    std::string Replace(std::string_view text, char replace, char replaceWith)
    {
        std::string result(text);

        std::replace(result.begin(), result.end(), replace, replaceWith);

        return result;
    }

    std::string GetFileExtension(std::string_view path)
    {
        std::string extension{path.substr(path.find_last_of('.') + 1).data()};

        return extension;
    }

    std::string GetFileNameNoExtension(std::string_view path)
    {
        auto nameWithExtension{std::string(path.substr(path.find_last_of('/') + 1))};

        return nameWithExtension.substr(0, nameWithExtension.find_last_of('.'));
    }

    Size GetCanvasSize()
    {
        Size canvasSize;

        auto window = _<SDLDevice>().GetWindow();

        SDL_GetWindowSize(window.get(), &canvasSize.width, &canvasSize.height);

        return canvasSize;
    }

    float GetAspectRatio()
    {
        auto canvasSize{GetCanvasSize()};

        if (canvasSize.height == 0)
        {
            throw std::runtime_error(
                "Utilities: Try to calculate aspect ratio when canvas height is 0.");
        }

        return static_cast<float>(canvasSize.width) / canvasSize.height;
    }

    float ConvertWidthToHeight(float width)
    {
        auto aspectRatio{GetAspectRatio()};

        return width * aspectRatio;
    }

    float ConvertHeightToWidth(float height)
    {
        auto aspectRatio{GetAspectRatio()};

        return height / aspectRatio;
    }

    int InvertSpeed(float speed)
    {
        return static_cast<int>(1000 / speed);
    }

    PointF GetMousePosition()
    {
        Point mousePositionPixels;

        SDL_GetMouseState(&mousePositionPixels.x, &mousePositionPixels.y);

        auto canvasSize{GetCanvasSize()};

        if (canvasSize.width == 0 || canvasSize.height == 0)
        {
            throw std::runtime_error("Utilities: Try to calculate mouse position when canvas size "
                                     "has a dimension of 0.");
        }

        auto mousePosition{PointF{
            static_cast<float>(mousePositionPixels.x) / canvasSize.width,
            static_cast<float>(mousePositionPixels.y) / canvasSize.height,
        }};

        return mousePosition;
    }
}