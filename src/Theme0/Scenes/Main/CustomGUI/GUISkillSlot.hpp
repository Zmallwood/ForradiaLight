/*
 * Copyright 2026 Andreas Åkerberg
 * This code is licensed under MIT license (see LICENSE for details)
 */

#pragma once

#include "Core/GUICore/GUIPanel.hpp"

namespace Forradia
{
    class GUISkillSlot : public GUIPanel
    {
      public:
        GUISkillSlot(int position);

        void SetSkillName(std::string_view skillName)
        {
            m_skillName = skillName;
        }

      protected:
        void RenderDerived() override;

        std::string GetBackgroundImage() const override;

      private:
        inline static const std::string k_backgroundImage{"GUISkillSlotBackground"};
        std::string m_skillName{""};
        int m_position{-1};
    };
}