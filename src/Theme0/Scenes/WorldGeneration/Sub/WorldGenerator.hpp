/*
 * Copyright 2026 Andreas Åkerberg
 * This code is licensed under MIT license (see LICENSE for details)
 */

#pragma once

namespace Forradia
{
    class WorldGenerator
    {
      public:
        void GenerateNewWorld();

      private:
        void ClearWorldWithGrass();

        void GenerateDirt();

        void GenerateWater();

        void GeneratObjects();
    };
}