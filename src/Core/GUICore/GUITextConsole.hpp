/*
 * Copyright 2026 Andreas Åkerberg
 * This code is licensed under MIT license (see LICENSE for details)
 */

#pragma once

#include "GUIPanel.hpp"

namespace Forradia
{
    /**
     * Represents a text console in the GUI, used as a singleton.
     */
    class GUITextConsole : public GUIPanel
    {
      public:
        GUITextConsole();

        void PrintLine(std::string_view line);

      protected:
        void RenderDerived() override;

      private:
        static constexpr float k_lineHeight{0.03f};

        std::vector<std::string> m_lines;
    };
}