/*
 * Copyright 2026 Andreas Åkerberg
 * This code is licensed under MIT license (see LICENSE for details)
 */

#pragma once

#include "Core/GUICore/GUIComponent.hpp"

namespace Forradia
{
    class GUISkillSlot;

    /**
     * Represents a set of skill slots in the GUI.
     */
    class GUISkillSlotSet : public GUIComponent
    {
      public:
        GUISkillSlotSet();

        std::shared_ptr<GUISkillSlot> GetSkillSlot(int index) const;

      private:
        std::vector<std::shared_ptr<GUISkillSlot>>
            m_skillSlots; ///< Contained skill slots in this set.
    };
}
