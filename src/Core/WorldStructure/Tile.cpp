/*
 * Copyright 2026 Andreas Åkerberg
 * This code is licensed under MIT license (see LICENSE for details)
 */

#include "Tile.hpp"
#include "ObjectsStack.hpp"

namespace Forradia
{
    Tile::Tile() : m_objectsStack(std::make_shared<ObjectsStack>())
    {
    }
}