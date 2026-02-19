/*
 * Copyright 2026 Andreas Åkerberg
 * This code is licensed under MIT license (see LICENSE for details)
 */

#pragma once

namespace Forradia
{
    template <class T>
    std::shared_ptr<T> GetSingletonPtr()
    {
        static std::shared_ptr<T> instance = std::make_shared<T>();

        return instance;
    }

    template <class T>
    T &_()
    {
        auto ptr{GetSingletonPtr<T>()};

        return *ptr;
    }
}