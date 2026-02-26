/*
 * Copyright 2026 Andreas Åkerberg
 * This code is licensed under MIT license (see LICENSE for details)
 */

#include "MouseButton.hpp"

namespace Forradia
{
    void MouseButton::Reset()
    {
        m_pressed = false;
    }

    void MouseButton::RegisterPress()
    {
        m_pressed = true;
    }

    void MouseButton::RegisterRelease()
    {
        m_pressed = false;
    }

    bool MouseButton::IsPressedLeaveResult()
    {
        return m_pressed;
    }

    bool MouseButton::IsPressedPickResult()
    {
        auto result{m_pressed};
        m_pressed = false;

        return result;
    }
}