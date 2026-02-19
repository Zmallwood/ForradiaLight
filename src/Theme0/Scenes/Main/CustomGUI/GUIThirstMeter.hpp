#pragma once

#include "Core/GUICore/GUIMeter.hpp"

namespace Forradia
{
    class GUIThirstMeter : public GUIMeter
    {
      public:
        GUIThirstMeter();

      protected:
        virtual float GetMeterProgress() override;

        std::string GetColorName() const override;
    };
}