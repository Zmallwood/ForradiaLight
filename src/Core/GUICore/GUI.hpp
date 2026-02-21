/*
 * Copyright 2026 Andreas Åkerberg
 * This code is licensed under MIT license (see LICENSE for details)
 */

#pragma once

#include "GUIComponent.hpp"

namespace Forradia
{
    /**
     * Represents a GUI, of which every scene has one.
     */
    class GUI : public GUIComponent
    {
      public:
        using GUIComponent::GUIComponent;
    };
}