/*
 * Copyright 2026 Andreas Åkerberg
 * This code is licensed under MIT license (see LICENSE for details)
 */

#pragma once

#include "Core/GUICore/GUIPanel.hpp"

namespace Forradia
{
    class GUIStatusPanel : public GUIPanel
    {
      public:
        GUIStatusPanel();

        void RenderDerived() override;
    };
}