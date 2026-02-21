/*
 * Copyright 2026 Andreas Åkerberg
 * This code is licensed under MIT license (see LICENSE for details)
 */

#pragma once

#include "GUIComponent.hpp"

namespace Forradia
{
    /**
     * Represents a meter in the GUI.
     */
    class GUIMeter : public GUIComponent
    {
      public:
        /**
         * Constructor.
         *
         * @param x X position.
         * @param y Y position.
         * @param width Width.
         * @param height Height.
         */
        GUIMeter(float x, float y, float width, float height);

        /**
         * Gets the height of this GUI meter.
         *
         * @return The height.
         */
        float GetHeight() const;

      protected:
        /**
         * The render logic specific to the GUIMeter.
         */
        virtual void RenderDerived() override;

        /**
         * Gets the progress, i.e. the percentage amount of how filled this meter is.
         *
         * @return The progress.
         */
        virtual float GetMeterProgress();

        /**
         * Gets the name of the color used for the filled area of this GUI meter.
         *
         * @return The name of the fill color.
         */
        virtual std::string GetFilledColorName() const;

      private:
        SizeF m_size; ///< Size in the canvas.
    };
}
