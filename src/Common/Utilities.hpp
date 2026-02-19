/*
 * Copyright 2026 Andreas Åkerberg
 * This code is licensed under MIT license (see LICENSE for details)
 */

#pragma once

namespace Forra
{
    std::string Replace(std::string_view text, char replace, char replaceWith);

    std::string GetFileExtension(std::string_view path);

    std::string GetFileNameNoExtension(std::string_view path);

    Size GetCanvasSize();

    float GetAspectRatio();

    float ConvertWidthToHeight(float width);

    float ConvertHeightToWidth(float height);

    int InvertSpeed(float speed);

    PointF GetMousePosition();
}