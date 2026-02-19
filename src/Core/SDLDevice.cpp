/*
 * Copyright 2026 Andreas Åkerberg
 * This code is licensed under MIT license (see LICENSE for details)
 */

#include "SDLDevice.hpp"

namespace Forradia
{
    void SDLDevice::Initialize()
    {
        SDL_Init(SDL_INIT_EVERYTHING);

        m_window = std::shared_ptr<SDL_Window>(
            SDL_CreateWindow("Forradia", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 660, 660,
                             SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE | SDL_WINDOW_MAXIMIZED |
                                 SDL_WINDOW_FULLSCREEN_DESKTOP),
            SDLDeleter());

        if (!m_window)
        {
            std::cout << "Window creation failed: " << std::string(SDL_GetError()) << std::endl;
            return;
        }

        m_renderer = std::shared_ptr<SDL_Renderer>(
            SDL_CreateRenderer(m_window.get(), -1, SDL_RENDERER_ACCELERATED), SDLDeleter());

        if (!m_renderer)
        {
            std::cout << "Renderer creation failed: " << std::string(SDL_GetError()) << std::endl;
            return;
        }
    }

    void SDLDevice::ClearCanvas()
    {
        if (!m_renderer)
        {
            throw std::runtime_error("SDLDevice: Renderer doesn't exist to clear canvas.");
        }

        SDL_SetRenderDrawBlendMode(m_renderer.get(), SDL_BLENDMODE_BLEND);
        SDL_SetRenderDrawColor(m_renderer.get(), 0, 150, 255, 255);

        SDL_RenderClear(m_renderer.get());
    }

    void SDLDevice::PresentCanvas()
    {
        if (!m_renderer)
        {
            throw std::runtime_error("SDLDevice: Renderer doesn't exist to present canvas.");
        }

        SDL_RenderPresent(m_renderer.get());
    }
}