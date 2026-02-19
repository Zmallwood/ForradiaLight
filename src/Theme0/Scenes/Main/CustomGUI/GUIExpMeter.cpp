/*
 * Copyright 2026 Andreas Åkerberg
 * This code is licensed under MIT license (see LICENSE for details)
 */

#include "GUIExpMeter.hpp"
#include "Theme0/Theme0Math/ExperienceMath.hpp"
#include "Core/CoreGameObjects/Player.hpp"

namespace Forradia
{
    GUIExpMeter::GUIExpMeter() : GUIMeter(0.0f, 0.97f, 1.0f, 0.03f)
    {
    }

    float GUIExpMeter::GetMeterProgress()
    {
        auto experience{_<Player>().GetExperience()};
        auto progress{CalculateFractionalExperienceProgress(experience)};

        return progress;
    }
}