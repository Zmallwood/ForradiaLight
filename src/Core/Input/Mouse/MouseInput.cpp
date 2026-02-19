/*
 * Copyright 2026 Andreas Åkerberg
 * This code is licensed under MIT license (see LICENSE for details)
 */

#include "MouseInput.hpp"

namespace Forradia
{
    MouseInput::MouseInput()
        : m_leftButton{std::make_shared<MouseButton>()},
          m_rightButton{std::make_shared<MouseButton>()}
    {
    }

    void MouseInput::RegisterButtonPress(Uint8 button)
    {
        switch (button)
        {
        case SDL_BUTTON_LEFT:
            m_leftButton->RegisterPress();
            break;
        case SDL_BUTTON_RIGHT:
            m_rightButton->RegisterPress();
            break;
        default:
            break;
        }
    }

    void MouseInput::RegisterButtonRelease(Uint8 button)
    {
        switch (button)
        {
        case SDL_BUTTON_LEFT:
            m_leftButton->RegisterRelease();
            break;
        case SDL_BUTTON_RIGHT:
            m_rightButton->RegisterRelease();
            break;
        default:
            break;
        }
    }

    bool MouseInput::AnyButtonIsPressedPickResult()
    {
        auto result{m_leftButton->IsPressedPickResult()};
        result |= m_rightButton->IsPressedPickResult();

        return result;
    }
}