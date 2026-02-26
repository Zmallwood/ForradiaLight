/*
 * Copyright 2026 Andreas Åkerberg
 * This code is licensed under MIT license (see LICENSE for details)
 */

#include "UpdateKeyboardHotkeys.hpp"
#include "Core/Input/Keyboard/KeyboardInput.hpp"
#include "Theme0/Scenes/Main/CustomGUI/GUIInventoryWindow.hpp"

namespace Forradia
{
    void UpdateKeyboardHotkeys()
    {
        if (_<KeyboardInput>().KeyIsPressedPickResult(SDLK_b))
        {
            _<GUIInventoryWindow>().ToggleVisibility();
        }
    }
}