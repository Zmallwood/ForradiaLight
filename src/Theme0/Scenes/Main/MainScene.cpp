/*
 * Copyright 2026 Andreas Åkerberg
 * This code is licensed under MIT license (see LICENSE for details)
 */

#include "MainScene.hpp"
#include "Sub/WorldView/WorldView.hpp"
#include "Sub/UpdateKeyboardMovement.hpp"
#include "Sub/UpdateMouseMovement.hpp"
#include "Sub/TileHovering.hpp"
#include "CustomGUI/GUIExpMeter.hpp"
#include "Core/GUICore/GUI.hpp"

namespace Forra
{
    void MainScene::InitializeDerived()
    {
        GetGUI()->AddComponent(std::make_shared<GUIExpMeter>());
    }

    void MainScene::UpdateDerived()
    {
        UpdateKeyboardMovement();

        _<TileHovering>().Update();

        UpdateMouseMovement();
    }

    void MainScene::RenderDerived()
    {
        _<WorldView>().Render();
    }
}