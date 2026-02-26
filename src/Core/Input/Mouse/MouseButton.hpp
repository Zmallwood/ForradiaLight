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
        /**
         * Registers this mouse button as have been pressed.
         */
        void RegisterPress();

        /**
         * Registers this mouse button as have been released.
         */
        void RegisterRelease();

        bool IsPressedLeaveResult();

        /**
         * Tells if this mouse button is currently being pressed, and resets the state.
         *
         * @return True if this button is being pressed, otherwise false.
         */
        bool IsPressedPickResult();

      private:
        bool m_pressed{false}; ///< State for if this button is being pressed.
    };
}
