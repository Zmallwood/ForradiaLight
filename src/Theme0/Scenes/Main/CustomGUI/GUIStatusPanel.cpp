/*
 * Copyright 2026 Andreas Åkerberg
 * This code is licensed under MIT license (see LICENSE for details)
 */

#include "GUIStatusPanel.hpp"
#include "Core/CoreGameObjects/Player.hpp"
#include "Core/Rendering/TextRenderer.hpp"
#include "Theme0/Theme0Math/ExperienceMath.hpp"
#include "GUIHungerMeter.hpp"
#include "GUIThirstMeter.hpp"

namespace Forradia
{
    GUIStatusPanel::GUIStatusPanel() : GUIPanel(0.0f, 0.0f, 0.2f, 0.2f)
    {
        AddComponent(std::make_shared<GUIHungerMeter>());

        AddComponent(std::make_shared<GUIThirstMeter>());
    }

    void GUIStatusPanel::RenderDerived()
    {
        GUIPanel::RenderDerived();

        _<TextRenderer>().DrawString(_<Player>().GetName(), FontSizes::_20, 0.03f, 0.03f);

        auto playerLevel{CalculateCurrentLevel(_<Player>().GetExperience())};

        std::string levelText{"Level " + std::to_string(playerLevel)};

        _<TextRenderer>().DrawString(levelText, FontSizes::_26, 0.03f, 0.07f, Palette::Gold);

        _<TextRenderer>().DrawString("Hunger", FontSizes::_20, 0.03f, 0.12f);

        _<TextRenderer>().DrawString("Thirst", FontSizes::_20, 0.03f, 0.15f);
    }
}