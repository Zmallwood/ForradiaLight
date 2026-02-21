/*
 * Copyright 2026 Andreas Åkerberg
 * This code is licensed under MIT license (see LICENSE for details)
 */

#pragma once

namespace Forradia
{
    /**
     * Represents the FPS counter, used to count the frames per second and render the FPS to the
     * canvas.
     */
    class FPSCounter
    {
      public:
        void Update();

        void Render();

      private:
        int m_fps{0};
        int m_frameCount{0};
        int m_ticksLastUpdate{0};
    };
}