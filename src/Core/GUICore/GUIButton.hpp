/*
 * Copyright 2026 Andreas Åkerberg
 * This code is licensed under MIT license (see LICENSE for details)
 */

#pragma once

#include "GUIPanel.hpp"

namespace Forradia
{
    class GUIButton : public GUIPanel
    {
      public:
        GUIButton(std::string_view text, float x, float y, float width, float height,
                  std::function<void()> action,
                  std::string_view backgroundImage = "GUIButtonBackground",
                  std::string_view hoveredBackgroundImage = "GUIButtonHoveredBackground");

      protected:
        void UpdateDerived() override;

        void RenderDerived() override;

        std::string GetBackgroundImage() const override;

      private:
        const std::string k_backgroundImage{"GUIButtonBackground"};
        const std::string k_hoveredBackgroundImage{"GUIButtonHoveredBackground"};
        std::string m_text;
        std::function<void()> m_action;
        bool m_hovered{false};
    };
}