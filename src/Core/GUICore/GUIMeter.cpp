/*
 * Copyright 2026 Andreas Åkerberg
 * This code is licensed under MIT license (see LICENSE for details)
 */

#include "GUIMeter.hpp"
#include "Core/Rendering/ImageRenderer.hpp"

namespace Forradia
{
    GUIMeter::GUIMeter(float x, float y, float width, float height)
        : GUIComponent(x, y), m_size(width, height)
    {
    }

    void GUIMeter::RenderDerived()
    {
        auto position{GetPosition()};
        auto size{m_size};

        _<ImageRenderer>().DrawImage("DarkBlue", position.x, position.y, size.width, size.height);
        _<ImageRenderer>().DrawImage(GetColorName(), position.x, position.y,
                                     GetMeterProgress() * size.width, size.height);
        _<ImageRenderer>().DrawImage("Black", position.x, position.y, size.width, 0.005f);
    }

    float GUIMeter::GetMeterProgress()
    {
        return 0.0f;
    }

    std::string GUIMeter::GetColorName() const
    {
        return "Gold";
    }
}