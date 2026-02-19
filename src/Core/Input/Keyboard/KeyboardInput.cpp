/*
 * Copyright 2026 Andreas Åkerberg
 * This code is licensed under MIT license (see LICENSE for details)
 */

#include "KeyboardInput.hpp"

namespace Forra
{
    void KeyboardInput::RegisterKeyPress(SDL_Keycode key)
    {
        m_pressedKeys.insert(key);
    }

    void KeyboardInput::RegisterKeyRelease(SDL_Keycode key)
    {
        m_pressedKeys.erase(key);
    }

    bool KeyboardInput::AnyKeyIsPressedPickResult()
    {
        auto result{m_pressedKeys.size() > 0};
        m_pressedKeys.clear();

        return result;
    }

    bool KeyboardInput::KeyIsPressed(SDL_Keycode key)
    {
        return m_pressedKeys.contains(key);
    }
}