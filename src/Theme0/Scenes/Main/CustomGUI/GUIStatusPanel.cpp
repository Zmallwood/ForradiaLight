/*
 * Copyright 2026 Andreas Åkerberg
 * This code is licensed under MIT license (see LICENSE for details)
 */

#include "GUIStatusPanel.hpp"
#include "Core/CoreGameObjects/Player.hpp"
#include "Core/Rendering/TextRenderer.hpp"
#include "Theme0/Theme0Math/ExperienceMath.hpp"

namespace Forradia
{
    GUIStatusPanel::GUIStatusPanel() : GUIPanel(0.0f, 0.0f, 0.18f, 0.15f)
    {
    }

    void GUIStatusPanel::RenderDerived()
    {
        GUIPanel::RenderDerived();

        _<TextRenderer>().DrawString(_<Player>().GetName(), FontSizes::_20, 0.03f, 0.03f);

        auto playerLevel{CalculateCurrentLevel(_<Player>().GetExperience())};

        std::string levelText{"Level " + std::to_string(playerLevel)};

        _<TextRenderer>().DrawString(levelText, FontSizes::_20, 0.03f, 0.06f);
    }
}