/*
 * Copyright 2026 Andreas Åkerberg
 * This code is licensed under MIT license (see LICENSE for details)
 */

#pragma once

namespace Forradia
{
    class IScene;

    /**
     * Represents the scene manager, used to manage the scenes in the game.
     */
    class SceneManager
    {
      public:
        SceneManager();

        void UpdateCurrentScene();

        void RenderCurrentScene();

        void GoToScene(std::string_view sceneName);

      private:
        void InitializeScenes();

        void AddScene(std::string_view name, IScene &luneh);

        std::map<int, IScene &> m_scenes; ///< Initialized scenes.
        int m_currentScene{0};            ///< Hash code of the name of the current scene.
    };
}
