/*
 * Copyright 2026 Andreas Åkerberg
 * This code is licensed under MIT license (see LICENSE for details)
 */

#include "IntroScene.hpp"
#include "Core/Rendering/ImageRenderer.hpp"
#include "Core/Input/Keyboard/KeyboardInput.hpp"
#include "Core/ScenesCore/SceneManager.hpp"
#include "Core/Input/Mouse/MouseInput.hpp"

namespace Forra
{
    void IntroScene::UpdateDerived()
    {
        if (_<KeyboardInput>().AnyKeyIsPressedPickResult() ||
            _<MouseInput>().AnyButtonIsPressedPickResult())
        {
            _<SceneManager>().GoToScene("MainMenuScene");
        }
    }

    void IntroScene::RenderDerived()
    {
        _<ImageRenderer>().DrawImage("FloratLunahNematin", 0.0f, 0.0f, 1.0f, 1.0f);

        _<ImageRenderer>().DrawImage("ForradiaLogo", 0.3f, 0.2f, 0.4f, 0.2f);
    }
}