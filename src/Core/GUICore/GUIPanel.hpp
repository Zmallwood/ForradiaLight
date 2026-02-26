/*
 * Copyright 2026 Andreas Åkerberg
 * This code is licensed under MIT license (see LICENSE for details)
 */

#pragma once

#include "GUIComponent.hpp"

namespace Forradia
{
    /**
     * Represents a panel in the GUI.
     */
    class GUIPanel : public GUIComponent
    {
      public:
        /**
         * Constructor.
         *
         * @param x X position.
         * @param y Y position.
         * @param width Width.
         * @param height Height.
         */
        GUIPanel(float x, float y, float width, float height);

        /**
         * Gets the height of this GUI panel.
         *
         * @return The height.
         */
        float GetHeight() const;

      protected:
        /**
         * Render logic specific to the GUIPanel.
         */
        virtual void RenderDerived() override;

        /**
         * Gets the background image name.
         *
         * @return The background image name.
         */
        virtual std::string GetBackgroundImage() const;

        auto GetSize() const
        {
            return m_size;
        }

        auto GetVisible() const
        {
            return m_isVisible;
        }

        void SetVisible(bool value)
        {
            m_isVisible = value;
        }

      private:
        inline static const std::string k_defaultBackgroundImage{"GUIPanelBackground"};

        SizeF m_size;           ///< Size in the canvas.
        bool m_isVisible{true}; ///< Whether the panel is visible.
    };
}
