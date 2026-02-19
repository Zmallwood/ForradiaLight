/*
 * Copyright 2026 Andreas Åkerberg
 * This code is licensed under MIT license (see LICENSE for details)
 */

#pragma once

namespace Forradia
{
    constexpr auto Hash(std::string_view text) -> int
    {
        // Use djb2 algorithm by Daniel J. Bernstein.
        constexpr unsigned long algorithmConstant{5381};

        unsigned long hash{algorithmConstant};

        for (char chr : text)
        {
            constexpr unsigned long algorithmFactor{33};

            hash = algorithmFactor * hash + static_cast<unsigned char>(chr);
        }

        return static_cast<int>(hash);
    }
}