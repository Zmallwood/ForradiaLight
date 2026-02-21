/*
 * Copyright 2026 Andreas Åkerberg
 * This code is licensed under MIT license (see LICENSE for details)
 */

#pragma once

#include "Core/GUICore/GUIMeter.hpp"

namespace Forradia
{
    /**
     * Represents the thirst meter in the GUI.
     */
    class GUIThirstMeter : public GUIMeter
    {
      public:
        GUIThirstMeter();

      protected:
        virtual float GetMeterProgress() override;

        std::string GetFilledColorName() const override;
    };
}
