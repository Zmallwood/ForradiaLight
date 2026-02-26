/*
 * Copyright 2026 Andreas Åkerberg
 * This code is licensed under MIT license (see LICENSE for details)
 */

#include "GUIHungerMeter.hpp"
#include "Core/CoreGameObjects/Player.hpp"

namespace Forradia
{
    GUIHungerMeter::GUIHungerMeter() : GUIMeter(0.08f, 0.08f, 0.08f, 0.015f)
    {
    }

    float GUIHungerMeter::GetMeterProgress()
    {
        return _<Player>().GetHunger();
    }

    std::string GUIHungerMeter::GetFilledColorName() const
    {
        return "Green";
    }
}
