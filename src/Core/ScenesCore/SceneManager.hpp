/*
 * Copyright 2026 Andreas Åkerberg
 * This code is licensed under MIT license (see LICENSE for details)
 */

#pragma once

namespace Forra
{
    class IScene;

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

        std::map<int, IScene &> m_lunehyn;
        int m_ehurdeLuneh{0};
    };
}