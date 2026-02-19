/*
 * Copyright 2026 Andreas Åkerberg
 * This code is licensed under MIT license (see LICENSE for details)
 */

#include "ObjectsStack.hpp"
#include "Object.hpp"

namespace Forradia
{
    void ObjectsStack::AddObject(std::string_view objectTypeName)
    {
        m_objects.push_back(std::make_shared<Object>(Hash(objectTypeName)));
    }

    bool ObjectsStack::HasObjectOfType(std::string_view objectTypeName) const
    {
        auto objectTypeHash{Hash(objectTypeName)};

        for (auto object : m_objects)
        {
            if (object->GetType() == objectTypeHash)
            {
                return true;
            }
        }
        return false;
    }

    int ObjectsStack::GetSize() const
    {
        return static_cast<int>(m_objects.size());
    }
}