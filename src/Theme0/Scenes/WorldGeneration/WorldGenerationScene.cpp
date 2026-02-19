/*
 * Copyright 2026 Andreas Åkerberg
 * This code is licensed under MIT license (see LICENSE for details)
 */

#include "WorldGenerationScene.hpp"
#include "Core/Input/Keyboard/KeyboardInput.hpp"
#include "Core/ScenesCore/SceneManager.hpp"
#include "Sub/WorldGenerator.hpp"
#include "Core/Input/Mouse/MouseInput.hpp"

namespace Forra
{
    void WorldGenerationScene::OnEnterDerived()
    {
        _<WorldGenerator>().GenerateNewWorld();
        _<SceneManager>().GoToScene("MainScene");
    }

    void WorldGenerationScene::UpdateDerived()
    {
    }

    void WorldGenerationScene::RenderDerived()
    {
    }
}