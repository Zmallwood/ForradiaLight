/*
 * Copyright 2026 Andreas Åkerberg
 * This code is licensed under MIT license (see LICENSE for details)
 */

#include "GUITextConsole.hpp"
#include "Core/Rendering/TextRenderer.hpp"

namespace Forradia
{
    GUITextConsole::GUITextConsole() : GUIPanel(0.0f, 0.8f, 0.4f, 0.2f)
    {
    }

    void GUITextConsole::PrintLine(std::string_view line)
    {
        m_lines.push_back(line.data());
    }

    void GUITextConsole::RenderDerived()
    {
        GUIPanel::RenderDerived();

        auto position{GetPosition()};

        auto size{GetSize()};

        auto maxNumLines{static_cast<int>(size.height / k_lineHeight)};

        auto iStart{std::max(0, static_cast<int>(m_lines.size() - maxNumLines))};
        auto rowIndex{0};

        for (auto line = iStart; line < m_lines.size(); line++)
        {
            if (line > m_lines.size() - 1)
            {
                break;
            }

            auto text{m_lines[line]};

            _<TextRenderer>().DrawString(text, FontSizes::_20, position.x + 0.01f,
                                         position.y + 0.01f + rowIndex * k_lineHeight);

            rowIndex++;
        }
    }
}