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
#include "CustomGUI/GUIStatusPanel.hpp"
#include "Core/GUICore/GUI.hpp"
#include "Core/CoreGameObjects/Player.hpp"
#include "Core/GUICore/GUITextConsole.hpp"

namespace Forradia
{
    void MainScene::InitializeDerived()
    {
        GetGUI()->AddComponent(GetSingletonPtr<GUITextConsole>());

        GetGUI()->AddComponent(GetSingletonPtr<GUIExpMeter>());

        GetGUI()->AddComponent(std::make_shared<GUIStatusPanel>());
    }

    void MainScene::OnEnterDerived()
    {
        _<Player>().Initialize();

        _<GUITextConsole>().SetYPosition(1.0f - _<GUITextConsole>().GetHeight() -
                                         _<GUIExpMeter>().GetHeight());
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