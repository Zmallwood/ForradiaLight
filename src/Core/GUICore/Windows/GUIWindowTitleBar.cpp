/*
 * Copyright 2026 Andreas Åkerberg
 * This code is licensed under MIT license (see LICENSE for details)
 */

#include "GUIWindowTitleBar.hpp"
#include "Core/Rendering/TextRenderer.hpp"

namespace Forradia
{
    GUIWindowTitleBar::GUIWindowTitleBar(std::string_view title)
        : GUIPanel(0.0f, 0.0f, 1.0f, 0.05f), m_title(title)
    {
    }

    void GUIWindowTitleBar::RenderDerived()
    {
        auto position{GetPosition()};

        _<TextRenderer>().DrawString(m_title, FontSizes::_20, position.x, position.y, Palette::Wheat);
    }
}