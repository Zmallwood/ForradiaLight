/*
 * Copyright 2026 Andreas Åkerberg
 * This code is licensed under MIT license (see LICENSE for details)
 */

#include "GUIComponent.hpp"

namespace Forradia
{
    GUIComponent::GUIComponent(float x, float y) : m_position(x, y)
    {
    }

    void GUIComponent::Update()
    {
        if (!GetVisible())
        {
            return;
        }

        if (m_parent && !m_parent->GetVisible())
        {
            return;
        }

        UpdateDerived();

        for (const auto &component : m_components)
        {
            component->Update();
        }
    }

    void GUIComponent::Render()
    {
        if (!GetVisible())
        {
            return;
        }

        if (m_parent && !m_parent->GetVisible())
        {
            return;
        }

        RenderDerived();

        for (const auto &component : m_components)
        {
            component->Render();
        }
    }

    std::shared_ptr<GUIComponent>
    GUIComponent::AddComponent(std::shared_ptr<GUIComponent> component)
    {
        component->m_parent = this;

        m_components.push_back(component);

        return component;
    }

    PointF GUIComponent::GetPosition() const
    {
        PointF finalPosition{0.0f, 0.0f};

        if (m_parent)
        {
            finalPosition += m_parent->GetPosition();
        }

        finalPosition += m_position;

        return finalPosition;
    }

    void GUIComponent::SetYPosition(float y)
    {
        m_position.y = y;
    }
}