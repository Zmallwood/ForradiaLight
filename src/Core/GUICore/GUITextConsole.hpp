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
        /**
         * Default constructor.
         */
        GUITextConsole();

        /**
         * Prints a text line to this text console.
         *
         * @param line The text line to print.
         */
        void PrintLine(std::string_view line);

      protected:
        /**
         * Render logic specific to the GUITextConsole.
         */
        void RenderDerived() override;

      private:
        static constexpr float k_lineHeight{0.03f}; ///< Line height in the canvas.
        std::vector<std::string>
            m_lines; ///< The lines that have been added, of which the last onces are printed.
    };
}
