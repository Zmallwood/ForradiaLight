/*
 * Copyright 2026 Andreas Åkerberg
 * This code is licensed under MIT license (see LICENSE for details)
 */

#pragma once

namespace Forradia
{
    /**
     * Represents a button of the mouse, used to register and obtain states of button presses and
     * releases.
     */
    class MouseButton
    {
      public:
        void RegisterPress();

        void RegisterRelease();

        bool IsPressedPickResult();

      private:
        bool m_pressed{false};
    };
}