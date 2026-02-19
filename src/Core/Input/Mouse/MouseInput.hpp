/*
 * Copyright 2026 Andreas Åkerberg
 * This code is licensed under MIT license (see LICENSE for details)
 */

#pragma once

#include "MouseButton.hpp"

namespace Forradia
{
    class MouseInput
    {
      public:
        MouseInput();

        void RegisterButtonPress(Uint8 button);

        void RegisterButtonRelease(Uint8 button);

        bool AnyButtonIsPressedPickResult();

        auto GetLeftButton() const
        {
            return m_leftButton;
        }

        auto GetRightButton() const
        {
            return m_rightButton;
        }

      private:
        std::shared_ptr<MouseButton> m_leftButton;
        std::shared_ptr<MouseButton> m_rightButton;
    };
}