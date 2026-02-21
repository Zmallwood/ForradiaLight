/*
 * Copyright 2026 Andreas Åkerberg
 * This code is licensed under MIT license (see LICENSE for details)
 */

#include "GUIThirstMeter.hpp"
#include "Core/CoreGameObjects/Player.hpp"

namespace Forradia
{
    GUIThirstMeter::GUIThirstMeter() : GUIMeter(0.08f, 0.15f, 0.08f, 0.015f)
    {
    }

    float GUIThirstMeter::GetMeterProgress()
    {
        return _<Player>().GetThirst();
    }

    std::string GUIThirstMeter::GetFilledColorName() const
    {
        return "BrightBlue";
    }
}
