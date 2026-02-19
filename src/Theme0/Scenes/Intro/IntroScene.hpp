/*
 * Copyright 2026 Andreas Åkerberg
 * This code is licensed under MIT license (see LICENSE for details)
 */

#pragma once

#include "Core/ScenesCore/IScene.hpp"

namespace Forra
{
    class IntroScene : public IScene
    {
      protected:
        void UpdateDerived() override;

        void RenderDerived() override;
    };
}