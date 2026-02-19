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
        UpdateDerived();

        for (const auto &component : m_components)
        {
            component->Update();
        }
    }

    void GUIComponent::Render()
    {
        RenderDerived();

        for (const auto &component : m_components)
        {
            component->Render();
        }
    }

    void GUIComponent::AddComponent(std::shared_ptr<GUIComponent> component)
    {
        m_components.push_back(component);
    }

    void GUIComponent::SetYPosition(float y)
    {
        m_position.y = y;
    }
}