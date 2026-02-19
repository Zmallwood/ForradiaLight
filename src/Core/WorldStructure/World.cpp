/*
 * Copyright 2026 Andreas Åkerberg
 * This code is licensed under MIT license (see LICENSE for details)
 */

#include "World.hpp"
#include "WorldArea.hpp"

namespace Forradia
{
    World::World()
    {
        m_currentWorldArea = std::make_shared<WorldArea>();
    }
}