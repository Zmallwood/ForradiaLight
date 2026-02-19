/*
 * Copyright 2026 Andreas Åkerberg
 * This code is licensed under MIT license (see LICENSE for details)
 */

#pragma once

namespace Forra
{
    int CalculateCurrentLevel(int experience);

    int CalculateExperienceForLevel(int level);

    int CalculateExperienceDifferenceToNextLevel(int experience);

    int CalculateExperienceRequiredForCurrentLevelStart(int experience);

    int CalculateExperienceGainedSinceLevelStart(int experience);

    float CalculateFractionalExperienceProgress(int experience);
}