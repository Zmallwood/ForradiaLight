/*
 * Copyright 2026 Andreas Åkerberg
 * This code is licensed under MIT license (see LICENSE for details)
 */

#include "FPSCounter.hpp"
#include "Core/Rendering/TextRenderer.hpp"

namespace Forradia
{
    void FPSCounter::Update()
    {
        auto now{SDL_GetTicks()};

        if (now > m_ticksLastUpdate + 1000)
        {
            m_fps = m_framesCount;
            m_framesCount = 0;
            m_ticksLastUpdate = now;
        }

        m_framesCount++;
    }

    void FPSCounter::Render()
    {
        std::string text{"FPS: " + std::to_string(m_fps)};

        _<TextRenderer>().DrawString(text, FontSizes::_20, 0.9f, 0.03f);
    }
}
