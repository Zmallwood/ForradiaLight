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

        _<TextRenderer>().DrawString(_<Player>().GetName(), FontSizes::_20, 0.015f, 0.01f);

        auto playerLevel{CalculateCurrentLevel(_<Player>().GetExperience())};

        std::string levelText{"Level " + std::to_string(playerLevel)};

        _<TextRenderer>().DrawString(levelText, FontSizes::_26, 0.015f, 0.04f, Palette::Gold);

        _<TextRenderer>().DrawString("Hunger", FontSizes::_14, 0.015f, 0.08f);

        _<TextRenderer>().DrawString("Thirst", FontSizes::_14, 0.015f, 0.11f);

        _<TextRenderer>().DrawString("Aura strength: " +
                                         std::to_string(_<Player>().GetAuraStrength()),
                                     FontSizes::_14, 0.015f, 0.14f);
    }
}