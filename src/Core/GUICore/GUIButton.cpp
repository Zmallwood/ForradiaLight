/*
 * Copyright 2026 Andreas Åkerberg
 * This code is licensed under MIT license (see LICENSE for details)
 */

#include "GUIButton.hpp"
#include "Core/Rendering/TextRenderer.hpp"
#include "Core/MinorComponents/Cursor.hpp"
#include "Core/Input/Mouse/MouseInput.hpp"

namespace Forradia
{
    GUIButton::GUIButton(std::string_view text, float x, float y, float width, float height,
                         std::function<void()> action, std::string_view backgroundImage,
                         std::string_view hoveredBackgroundImage)
        : GUIPanel(x, y, width, height), m_text(text), m_action(action),
          k_backgroundImage(backgroundImage), k_hoveredBackgroundImage(hoveredBackgroundImage)
    {
    }

    void GUIButton::UpdateDerived()
    {
        GUIPanel::UpdateDerived();

        auto position{GetPosition()};

        auto size{GetSize()};

        auto rect{RectF{position.x, position.y, size.width, size.height}};

        if (rect.Contains(GetMousePosition()))
        {
            m_hovered = true;

            _<Cursor>().SetCursorStyle(CursorStyles::Hovering);

            if (_<MouseInput>().GetLeftButton()->IsPressedLeaveResult())
            {
                m_action();

                _<MouseInput>().GetLeftButton()->Reset();
            }
        }
        else
        {
            m_hovered = false;
        }
    }

    void GUIButton::RenderDerived()
    {
        GUIPanel::RenderDerived();

        auto position{GetPosition()};

        auto size{GetSize()};

        _<TextRenderer>().DrawString(m_text, FontSizes::_20, position.x + size.width / 2.0f,
                                     position.y + size.height / 2.0f, Palette::Wheat, true);
    }

    std::string GUIButton::GetBackgroundImage() const
    {
        return m_hovered ? k_hoveredBackgroundImage : k_backgroundImage;
    }
}