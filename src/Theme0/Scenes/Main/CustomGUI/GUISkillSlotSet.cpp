/*
 * Copyright 2026 Andreas Åkerberg
 * This code is licensed under MIT license (see LICENSE for details)
 */

#include "GUISkillSlotSet.hpp"
#include "GUISkillSlot.hpp"

namespace Forradia
{
    GUISkillSlotSet::GUISkillSlotSet() : GUIComponent(0.0f, 0.0f)
    {
        for (int i = 0; i < 5; i++)
        {
            m_skillSlots.push_back(std::make_shared<GUISkillSlot>(i));

            AddComponent(m_skillSlots.at(i));
        }
    }

    std::shared_ptr<GUISkillSlot> GUISkillSlotSet::GetSkillSlot(int index) const
    {
        return m_skillSlots.at(index);
    }
}