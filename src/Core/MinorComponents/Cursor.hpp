/*
 * Copyright 2026 Andreas Åkerberg
 * This code is licensed under MIT license (see LICENSE for details)
 */

#pragma once

namespace Forradia
{
    /**
     * Represents the cursor, used to render the game cursor to the canvas.
     */
    class Cursor
    {
      public:
        void Initialize();

        void Render() const;

      private:
        static constexpr float k_cursorWidth{
            0.05f}; ///< The width of the cursor icon in the canvas.
    };
}
