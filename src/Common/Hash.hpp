/*
 * Copyright 2026 Andreas Åkerberg
 * This code is licensed under MIT license (see LICENSE for details)
 */

#pragma once

namespace Forradia
{
    /**
     * Computes hash code for a text string.
     *
     * @param text Text to compute hash code for.
     * @return Computed hash code.
     */
    constexpr int Hash(std::string_view text)
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
