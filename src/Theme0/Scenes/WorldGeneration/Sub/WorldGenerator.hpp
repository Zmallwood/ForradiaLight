/*
 * Copyright 2026 Andreas Åkerberg
 * This code is licensed under MIT license (see LICENSE for details)
 */

#pragma once

namespace Forra
{
    class WorldGenerator
    {
      public:
        void GenerateNewWorld();

      private:
        void ClearWorldWithGrass();

        void GenerateWater();

        void GeneratObjects();
    };
}