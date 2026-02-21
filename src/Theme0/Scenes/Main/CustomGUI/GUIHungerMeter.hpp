/*
 * Copyright 2026 Andreas Åkerberg
 * This code is licensed under MIT license (see LICENSE for details)
 */

#pragma once

#include "Core/GUICore/GUIMeter.hpp"

namespace Forradia
{
    /**
     * Represents the hunger meter in the GUI.
     */
    class GUIHungerMeter : public GUIMeter
    {
      public:
        GUIHungerMeter();

      protected:
        virtual float GetMeterProgress() override;

        virtual std::string GetFilledColorName() const override;
    };
}
