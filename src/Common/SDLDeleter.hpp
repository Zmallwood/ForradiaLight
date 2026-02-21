/*
 * Copyright 2026 Andreas Åkerberg
 * This code is licensed under MIT license (see LICENSE for details)
 */

#pragma once

namespace Forradia
{
    /**
     * Represents a deleter for SDL objects, used for automatic cleanup.
     */
    class SDLDeleter
    {
      public:
        /**
         * Automatic cleanup of SDL window object.
         *
         * @param window Window to cleanup.
         */
        void operator()(SDL_Window *window) const;

        /**
         * Automatic cleanup of SDL renderer object.
         *
         * @param window Renderer to cleanup.
         */
        void operator()(SDL_Renderer *renderer) const;

        /**
         * Automatic cleanup of SDL surface object.
         *
         * @param window Surface to cleanup.
         */
        void operator()(SDL_Surface *surface) const;

        /**
         * Automatic cleanup of SDL texture object.
         *
         * @param window Texture to cleanup.
         */
        void operator()(SDL_Texture *texture) const;

        /**
         * Automatic cleanup of TTF font object.
         *
         * @param window Font to cleanup.
         */
        void operator()(TTF_Font *font) const;
    };
}
