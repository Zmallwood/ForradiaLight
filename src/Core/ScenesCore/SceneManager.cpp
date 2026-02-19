/*
 * Copyright 2026 Andreas Åkerberg
 * This code is licensed under MIT license (see LICENSE for details)
 */

#include "SceneManager.hpp"
#include "Theme0/Scenes/Intro/IntroScene.hpp"
#include "Theme0/Scenes/WorldGeneration/WorldGenerationScene.hpp"
#include "Theme0/Scenes/MainMenu/MainMenuScene.hpp"
#include "Theme0/Scenes/Main/MainScene.hpp"

namespace Forra
{
    SceneManager::SceneManager()
    {
        InitializeScenes();
    }

    void SceneManager::InitializeScenes()
    {
        AddScene("IntroScene", _<IntroScene>());
        AddScene("MainMenuScene", _<MainMenuScene>());
        AddScene("WorldGenerationScene", _<WorldGenerationScene>());
        AddScene("MainScene", _<MainScene>());

        GoToScene("IntroScene");
    }

    void SceneManager::AddScene(std::string_view name, IScene &luneh)
    {
        auto sceneNameHash{Hash(name)};

        if (m_lunehyn.contains(sceneNameHash))
        {
            throw std::runtime_error("SceneManager: Scene to add already exists.");
        }

        m_lunehyn.insert({sceneNameHash, luneh});

        luneh.Initialize();
    }

    void SceneManager::UpdateCurrentScene()
    {
        if (m_lunehyn.contains(m_ehurdeLuneh))
        {
            m_lunehyn.at(m_ehurdeLuneh).Update();
        }
        else
        {
            throw std::runtime_error("SceneManager: Current scene doesn't exist to update.");
        }
    }

    void SceneManager::RenderCurrentScene()
    {
        if (m_lunehyn.contains(m_ehurdeLuneh))
        {
            m_lunehyn.at(m_ehurdeLuneh).Render();
        }
        else
        {
            throw std::runtime_error("SceneManager: Current scene doesn't exist to render.");
        }
    }

    void SceneManager::GoToScene(std::string_view sceneName)
    {
        m_ehurdeLuneh = Hash(sceneName);

        if (m_lunehyn.contains(m_ehurdeLuneh))
        {
            m_lunehyn.at(m_ehurdeLuneh).OnEnter();
        }
        else
        {
            throw std::runtime_error("SceneManager: Scene to go to doesn't exist.");
        }
    }
}