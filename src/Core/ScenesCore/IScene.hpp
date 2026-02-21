/*
 * Copyright 2026 Andreas Åkerberg
 * This code is licensed under MIT license (see LICENSE for details)
 */

#pragma once

namespace Forradia
{
    class GUI;

    /**
     * Represents a scene in the game.
     */
    class IScene
    {
      public:
        IScene();

        void Initialize();

        void OnEnter();

        void Update();

        void Render();

      protected:
        virtual void InitializeDerived()
        {
        }

        virtual void OnEnterDerived()
        {
        }

        virtual void UpdateDerived()
        {
        }

        virtual void RenderDerived()
        {
        }

        auto GetGUI() const
        {
            return m_gui;
        }

      private:
        std::shared_ptr<GUI> m_gui; ///< GUI instance for this scene.
    };
}
