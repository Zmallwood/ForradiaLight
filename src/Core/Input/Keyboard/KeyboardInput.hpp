/*
 * Copyright 2026 Andreas Åkerberg
 * This code is licensed under MIT license (see LICENSE for details)
 */

#pragma once

namespace Forradia
{
    class KeyboardInput
    {
      public:
        void RegisterKeyPress(SDL_Keycode key);

        void RegisterKeyRelease(SDL_Keycode key);

        bool AnyKeyIsPressedPickResult();

        bool KeyIsPressed(SDL_Keycode key);

        bool KeyIsPressedPickResult(SDL_Keycode key);

      private:
        std::set<SDL_Keycode> m_pressedKeys;
    };
}