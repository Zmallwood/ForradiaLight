/*
 * Copyright 2026 Andreas Åkerberg
 * This code is licensed under MIT license (see LICENSE for details)
 */

#pragma once

#include "GUIComponent.hpp"

namespace Forradia
{
    class GUIPanel : public GUIComponent
    {
      public:
        GUIPanel(float x, float y, float width, float height);

        float GetHeight() const;

      protected:
        virtual void RenderDerived() override;

        virtual std::string GetBackgroundImage() const;

        auto GetSize() const
        {
            return m_size;
        }

      private:
        inline static const std::string k_defaultBackgroundImage{"GUIPanelBackground"};

        SizeF m_size;
    };
}