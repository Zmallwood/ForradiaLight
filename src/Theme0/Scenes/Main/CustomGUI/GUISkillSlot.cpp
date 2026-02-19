/*
 * Copyright 2026 Andreas Åkerberg
 * This code is licensed under MIT license (see LICENSE for details)
 */

#include "GUISkillSlot.hpp"
#include "Common/Utilities.hpp"
#include "Core/Rendering/ImageRenderer.hpp"
#include "Core/Rendering/TextRenderer.hpp"

namespace Forradia
{
    GUISkillSlot::GUISkillSlot(int position)
        : GUIPanel(0.45f + 0.07f * position, 0.88f, 0.05f, ConvertWidthToHeight(0.05f)),
          m_position(position)
    {
    }

    void GUISkillSlot::RenderDerived()
    {
        GUIPanel::RenderDerived();

        auto position{GetPosition()};

        auto size{GetSize()};

        if (!m_skillName.empty())
        {
            std::string imageName{"GUISkillIcon" + m_skillName};

            _<ImageRenderer>().DrawImage(imageName, position.x, position.y, size.width,
                                         size.height);
        }

        std::string skillNumber{std::to_string(m_position + 1)};

        _<TextRenderer>().DrawString(skillNumber, FontSizes::_26, position.x + 0.01f,
                                     position.y + 0.01f, Palette::Black);
    }

    std::string GUISkillSlot::GetBackgroundImage() const
    {
        return k_backgroundImage;
    }
}