/*
 * Copyright 2026 Andreas Åkerberg
 * This code is licensed under MIT license (see LICENSE for details)
 */

#include "IScene.hpp"
#include "Core/GUICore/GUI.hpp"

namespace Forra
{
    IScene::IScene() : m_gui(std::make_shared<GUI>())
    {
    }

    void IScene::Initialize()
    {
        InitializeDerived();
    }

    void IScene::OnEnter()
    {
        OnEnterDerived();
    }

    void IScene::Update()
    {
        m_gui->Update();

        UpdateDerived();
    }

    void IScene::Render()
    {
        RenderDerived();

        m_gui->Render();
    }
}