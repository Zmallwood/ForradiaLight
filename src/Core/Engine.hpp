/*
 * Copyright 2026 Andreas Åkerberg
 * This code is licensed under MIT license (see LICENSE for details)
 */

#pragma once

namespace Forradia
{
    /**
     * Represents the engine of the game.
     */
    class Engine
    {
      public:
        void Run();

        void Stop();

      private:
        void Randomize();

        void PollEvents();

        bool m_running{true}; ///< Running state of the engine.
    };
}
