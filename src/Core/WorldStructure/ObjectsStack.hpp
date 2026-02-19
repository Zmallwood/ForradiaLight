/*
 * Copyright 2026 Andreas Åkerberg
 * This code is licensed under MIT license (see LICENSE for details)
 */

#pragma once

namespace Forradia
{
    class Object;

    class ObjectsStack
    {
      public:
        void AddObject(std::string_view objectTypeName);

        bool HasObjectOfType(std::string_view objectTypeName) const;

        int GetSize() const;

        auto GetObjects()
        {
            return m_objects;
        }

      private:
        std::vector<std::shared_ptr<Object>> m_objects;
    };
}