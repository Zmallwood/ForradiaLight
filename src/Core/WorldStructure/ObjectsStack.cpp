/*
 * Copyright 2026 Andreas Åkerberg
 * This code is licensed under MIT license (see LICENSE for details)
 */

#include "ObjectsStack.hpp"
#include "Object.hpp"

namespace Forra
{
    void ObjectsStack::AddObject(std::string_view objectTypeName)
    {
        m_objects.push_back(std::make_shared<Object>(Hash(objectTypeName)));
    }
}