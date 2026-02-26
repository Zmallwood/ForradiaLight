/*
 * Copyright 2026 Andreas Åkerberg
 * This code is licensed under MIT license (see LICENSE for details)
 */

#pragma once

#include "Core/GUICore/GUIPanel.hpp"

namespace Forradia
{
    class GUIWindowTitleBar;

    /**
     * Represents a window in the GUI.
     */
    class GUIWindow : public GUIPanel
    {
      public:
        GUIWindow(std::string_view title, float x, float y, float width, float height);

        void ToggleVisibility();
    };
}