/*
 * Copyright 2026 Andreas Åkerberg
 * This code is licensed under MIT license (see LICENSE for details)
 */

#include "GUIWindow.hpp"
#include "GUIWindowTitleBar.hpp"

namespace Forradia
{
    GUIWindow::GUIWindow(std::string_view title, float x, float y, float width, float height)
        : GUIPanel(x, y, width, height)
    {
        SetVisible(false);

        AddComponent(std::make_shared<GUIWindowTitleBar>(title));
    }

    void GUIWindow::ToggleVisibility()
    {
        if (GetVisible())
        {
            SetVisible(false);
        }
        else
        {
            SetVisible(true);
        }
    }
}