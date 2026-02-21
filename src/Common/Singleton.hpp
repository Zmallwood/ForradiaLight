/*
 * Copyright 2026 Andreas Åkerberg
 * This code is licensed under MIT license (see LICENSE for details)
 */

#pragma once

namespace Forradia
{
    /**
     * Returns a singleton of a class as a pointer.
     *
     * @tparam T Type to get singleton of.
     * @return Singleton pointer.
     */
    template <class T>
    std::shared_ptr<T> GetSingletonPtr()
    {
        static std::shared_ptr<T> instance = std::make_shared<T>();

        return instance;
    }

    /**
     * Returns a singleton of a class as a reference.
     *
     * @tparam T Type to get singleton of.
     * @return Singleton reference.
     */
    template <class T>
    T &_()
    {
        auto ptr{GetSingletonPtr<T>()};

        return *ptr;
    }
}
