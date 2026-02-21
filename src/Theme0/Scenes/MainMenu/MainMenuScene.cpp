/*
 * Copyright 2026 Andreas Åkerberg
 * This code is licensed under MIT license (see LICENSE for details)
 */

#include "MainMenuScene.hpp"
#include "Core/Input/Keyboard/KeyboardInput.hpp"
#include "Core/ScenesCore/SceneManager.hpp"
#include "Core/Input/Mouse/MouseInput.hpp"
#include "Core/Rendering/ImageRenderer.hpp"
#include "Core/GUICore/GUI.hpp"
#include "Core/GUICore/GUIPanel.hpp"
#include "Core/GUICore/GUITextConsole.hpp"

namespace Forradia
{
    void MainMenuScene::InitializeDerived()
    {
        GetGUI()->AddComponent(GetSingletonPtr<GUITextConsole>());

        GetGUI()->AddComponent(std::make_shared<GUIPanel>(0.4f, 0.4f, 0.2f, 0.2f));
    }

    void MainMenuScene::OnEnterDerived()
    {
        _<GUITextConsole>().SetYPosition(1.0f - _<GUITextConsole>().GetHeight());
    }

    void MainMenuScene::UpdateDerived()
    {
        if (_<KeyboardInput>().AnyKeyIsPressedPickResult() ||
            _<MouseInput>().AnyButtonIsPressedPickResult())
        {
            _<SceneManager>().GoToScene("WorldGenerationScene");
        }
    }

    void MainMenuScene::RenderDerived()
    {
        _<ImageRenderer>().DrawImage("DefaultSceneBackground", 0.0f, 0.0f, 1.0f, 1.0f);

        _<ImageRenderer>().DrawImage("ForradiaLogo", 0.4f, 0.15f, 0.2f, 0.1f);
    }
}
