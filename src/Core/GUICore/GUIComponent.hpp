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
        /**
         * Default constructor.
         */
        GUIComponent() = default;

        /**
         * Constructor.
         *
         * @param x X position.
         * @param y Y position.
         */
        GUIComponent(float x, float y);

        /**
         * Updates this GUI component.
         */
        void Update();

        /**
         * Renders this GUI component.
         */
        void Render();

        /**
         * Adds a child component to this component.
         *
         * @param component The child component to add.
         */
        void AddComponent(std::shared_ptr<GUIComponent> component);

        /**
         * Sets the y position of this GUI component to a new value.
         *
         * @param y New y position value.
         */
        void SetYPosition(float y);

      protected:
        /**
         * Update logic that is defined in inheriting classes.
         */
        virtual void UpdateDerived()
        {
        }

        /**
         * Render logic that is defined in inheriting classes.
         */
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
