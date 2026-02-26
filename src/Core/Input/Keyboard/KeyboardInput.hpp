/*
 * Copyright 2026 Andreas Åkerberg
 * This code is licensed under MIT license (see LICENSE for details)
 */

#pragma once

namespace Forradia
{
    /**
     * Represents the keyboard input, used to register and obtain states of key presses and
     * releases.
     */
    class KeyboardInput
    {
      public:
        /**
         * Registers a key as have been pressed.
         *
         * @param key Key to register.
         */
        void RegisterKeyPress(SDL_Keycode key);

        /**
         * Registers a key as have been released.
         *
         * @param key Key to register.
         */
        void RegisterKeyRelease(SDL_Keycode key);

        /**
         * Tells if any key is currently being pressed, and resets the state.
         *
         * @return True if any key is being pressed, otherwise false.
         */
        bool AnyKeyIsPressedPickResult();

        /**
         * Tells if a specific key is currently being pressed, without resetting the state.
         *
         * @param key Key to check.
         * @return True if the key is being pressed, otherwise false.
         */
        bool KeyIsPressed(SDL_Keycode key);

        /**
         * Tells if a specific key is currently being pressed, and resets the state.
         *
         * @param key Key to check.
         * @return True if the key is being pressed, otherwise false.
         */
        bool KeyIsPressedPickResult(SDL_Keycode key);

      private:
        std::set<SDL_Keycode> m_pressedKeys; ///< Keys that are currently being pressed.
    };
}
