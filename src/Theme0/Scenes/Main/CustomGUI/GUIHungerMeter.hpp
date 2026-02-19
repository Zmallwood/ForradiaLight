#pragma once

#include "Core/GUICore/GUIMeter.hpp"

namespace Forradia
{
    class GUIHungerMeter : public GUIMeter
    {
      public:
        GUIHungerMeter();

      protected:
        virtual float GetMeterProgress() override;

        virtual std::string GetColorName() const override;
    };
}