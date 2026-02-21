/*
 * Copyright 2026 Andreas Åkerberg
 * This code is licensed under MIT license (see LICENSE for details)
 */

#pragma once

namespace Forradia
{
    /**
     * Represents a component of a GUI.
     */
    class GUIComponent
    {
      public:
        GUIComponent() = default;

        GUIComponent(float x, float y);

        void Update();

        void Render();

        void AddComponent(std::shared_ptr<GUIComponent> component);

        void SetYPosition(float y);

      protected:
        virtual void UpdateDerived()
        {
        }

        virtual void RenderDerived()
        {
        }

        auto GetPosition() const
        {
            return m_position;
        }

      private:
        std::vector<std::shared_ptr<GUIComponent>>
            m_components;              ///< Child components of this component.
        PointF m_position{0.0f, 0.0f}; ///< Position in the canvas.
    };
}
