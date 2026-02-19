#include "GUIHungerMeter.hpp"
#include "Core/CoreGameObjects/Player.hpp"

namespace Forradia
{
    GUIHungerMeter::GUIHungerMeter() : GUIMeter(0.08f, 0.09f, 0.08f, 0.01f)
    {
    }

    float GUIHungerMeter::GetMeterProgress()
    {
        return _<Player>().GetHunger();
    }

    std::string GUIHungerMeter::GetColorName() const
    {
        return "Green";
    }
}