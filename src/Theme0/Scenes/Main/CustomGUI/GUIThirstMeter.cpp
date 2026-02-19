#include "GUIThirstMeter.hpp"
#include "Core/CoreGameObjects/Player.hpp"

namespace Forradia
{
    GUIThirstMeter::GUIThirstMeter() : GUIMeter(0.08f, 0.12f, 0.08f, 0.01f)
    {
    }

    float GUIThirstMeter::GetMeterProgress()
    {
        return _<Player>().GetThirst();
    }

    std::string GUIThirstMeter::GetColorName() const
    {
        return "BrightBlue";
    }
}