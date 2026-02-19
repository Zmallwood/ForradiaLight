/*
 * Copyright 2026 Andreas Åkerberg
 * This code is licensed under MIT license (see LICENSE for details)
 */

#pragma once

#include "Core/GUICore/GUIMeter.hpp"

namespace Forra
{
    class GUIExpMeter : public GUIMeter
    {
      public:
        GUIExpMeter();

      protected:
        virtual float GetMeterProgress() override;
    };
}