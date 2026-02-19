#include "GUISkillSlot.hpp"
#include "Common/Utilities.hpp"

namespace Forradia
{
    GUISkillSlot::GUISkillSlot(int position)
        : GUIPanel(0.45f + 0.07f * position, 0.88f, 0.05f, ConvertWidthToHeight(0.05f))
    {
    }

    std::string GUISkillSlot::GetBackgroundImage() const
    {
        return k_backgroundImage;
    }
}