/*
 * Copyright 2026 Andreas Åkerberg
 * This code is licensed under MIT license (see LICENSE for details)
 */

#include "GUIPanel.hpp"
#include "Core/Rendering/ImageRenderer.hpp"

namespace Forra
{
    GUIPanel::GUIPanel(float x, float y, float width, float height)
        : GUIComponent(x, y), m_size(width, height)
    {
    }

    void GUIPanel::RenderDerived()
    {
        auto position{GetPosition()};

        _<ImageRenderer>().DrawImage(k_defaultBackgroundImage, position.x, position.y, m_size.width,
                                     m_size.height);
    }
}