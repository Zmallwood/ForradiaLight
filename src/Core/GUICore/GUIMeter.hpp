/*
 * Copyright 2026 Andreas Åkerberg
 * This code is licensed under MIT license (see LICENSE for details)
 */

#pragma once

#include "GUIComponent.hpp"

namespace Forradia
{
    class GUIMeter : public GUIComponent
    {
      public:
        GUIMeter(float x, float y, float width, float height);

      protected:
        virtual void RenderDerived() override;

        virtual float GetMeterProgress();

        virtual std::string GetColorName() const;

      private:
        SizeF m_size;
    };
}