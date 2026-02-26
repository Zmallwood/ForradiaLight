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
                  std::function<void()> action);

      protected:
        void UpdateDerived() override;

        void RenderDerived() override;

        std::string GetBackgroundImage() const override;

      private:
        inline static const std::string k_backgroundImage{"GUIButtonBackground"};
        inline static const std::string k_hoveredBackgroundImage{"GUIButtonHoveredBackground"};
        std::string m_text;
        std::function<void()> m_action;
        bool m_hovered{false};
    };
}