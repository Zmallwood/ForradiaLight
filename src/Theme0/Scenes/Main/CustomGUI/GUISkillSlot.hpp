#pragma once

#include "Core/GUICore/GUIPanel.hpp"

namespace Forradia
{
    class GUISkillSlot : public GUIPanel
    {
      public:
        GUISkillSlot(int position);

      protected:
        std::string GetBackgroundImage() const override;

      private:
        inline static const std::string k_backgroundImage{"GUISkillSlotBackground"};
    };
}