/*
 * Copyright 2026 Andreas Åkerberg
 * This code is licensed under MIT license (see LICENSE for details)
 */

#pragma once

namespace Forra
{
    class Object;

    class ObjectsStack
    {
      public:
        void AddObject(std::string_view objectTypeName);

        auto GetObjects()
        {
            return m_objects;
        }

      private:
        std::vector<std::shared_ptr<Object>> m_objects;
    };
}