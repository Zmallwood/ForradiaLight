/*
 * Copyright 2026 Andreas Åkerberg
 * This code is licensed under MIT license (see LICENSE for details)
 */

#pragma once

namespace Forradia
{
    /**
     * Replaces all occurrences of a character in a string with another character.
     *
     * @param text Text to replace characters in.
     * @param replace Character to replace with the other character.
     * @param replaceWith The character to replace with.
     * @return The updated string.
     */
    std::string Replace(std::string_view text, char replace, char replaceWith);

    /**
     * Extracts and returns the file extension of a file path.
     *
     * @param path The path to extract the file extension from.
     * @return The file extension.
     */
    std::string GetFileExtension(std::string_view path);

    /**
     * Extracts the file name, without the extension, for a file path.
     *
     * @param path The path to extract the file name from.
     * @return The file name, without extension.
     */
    std::string GetFileNameNoExtension(std::string_view path);

    /**
     * Returns the canvas size, in pixels.
     *
     * @return The canvas size.
     */
    Size GetCanvasSize();

    /**
     * Returns the aspect ratio of the canvas.
     *
     * @param The aspect ratio.
     */
    float GetAspectRatio();

    /**
     * Converts a width in the canvas to the corresponding height.
     *
     * @param width Width value to convert.
     * @return The height.
     */
    float ConvertWidthToHeight(float width);

    /**
     * Converts a height in the canvas to the corresponding width.
     *
     * @param height Height value to convert.
     * @return The width.
     */
    float ConvertHeightToWidth(float height);

    /**
     * Inverts a speed value.
     *
     * @param speed Speed to invert.
     * @return The inverted speed.
     */
    int InvertSpeed(float speed);

    /**
     * Returns the mouse position in the canvas, as normalized value to the canvas size.
     *
     * @return The mouse position.
     */
    PointF GetMousePosition();
}
