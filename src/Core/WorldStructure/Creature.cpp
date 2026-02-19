/*
 * Copyright 2026 Andreas Åkerberg
 * This code is licensed under MIT license (see LICENSE for details)
 */

#include "Creature.hpp"

namespace Forradia
{
    Creature::Creature(std::string_view creatureTypeName) : m_type(Hash(creatureTypeName))
    {
    }
}