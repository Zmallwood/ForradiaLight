/*
 * Copyright 2026 Andreas Åkerberg
 * This code is licensed under MIT license (see LICENSE for details)
 */

#pragma once

#include "Core/ScenesCore/IScene.hpp"

namespace Forradia
{
    /**
     * Represents the intro scene, used to display the intro screen.
     */
    class IntroScene : public IScene
    {
      protected:
        void UpdateDerived() override;

        void RenderDerived() override;
    };
}