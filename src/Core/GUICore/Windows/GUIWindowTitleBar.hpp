/*
 * Copyright 2026 Andreas Åkerberg
 * This code is licensed under MIT license (see LICENSE for details)
 */

#pragma once

#include "Core/GUICore/GUIPanel.hpp"

namespace Forradia
{
    /**
     * Represents a title bar in a window.
     */
    class GUIWindowTitleBar : public GUIPanel
    {
      public:
        GUIWindowTitleBar(std::string_view title);

      protected:
        void RenderDerived() override;

      private:
        std::string m_title; ///< The title of the title bar.
    };
}