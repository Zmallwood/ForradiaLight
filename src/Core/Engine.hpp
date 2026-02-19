/*
 * Copyright 2026 Andreas Åkerberg
 * This code is licensed under MIT license (see LICENSE for details)
 */

#pragma once

namespace Forra
{
    class Engine
    {
      public:
        void Run();

      private:
        void Randomize();

        void PollEvents();

        bool m_running{true};
    };
}