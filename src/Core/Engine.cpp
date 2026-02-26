/*
 * Copyright 2026 Andreas Åkerberg
 * This code is licensed under MIT license (see LICENSE for details)
 */

#include "Engine.hpp"
#include "SDLDevice.hpp"
#include "Assets/ImageBank.hpp"
#include "ScenesCore/SceneManager.hpp"
#include "Input/Keyboard/KeyboardInput.hpp"
#include "Input/Mouse/MouseInput.hpp"
#include "MinorComponents/Cursor.hpp"
#include "Core/Rendering/TextRenderer.hpp"
#include "Core/MinorComponents/FPSCounter.hpp"

namespace Forradia
{
    void Engine::Run()
    {
        try
        {
            Randomize();

            _<SDLDevice>().Initialize();

            _<ImageBank>().LoadImages();

            _<TextRenderer>().Initialize();

            _<Cursor>().Initialize();

            while (m_running)
            {
                _<SDLDevice>().ClearCanvas();

                _<SceneManager>().RenderCurrentScene();

                _<FPSCounter>().Render();

                _<Cursor>().Render();

                _<SDLDevice>().PresentCanvas();

                // Poll events and do the updating at end of iteration to make sure that the
                // m_running check is done before rendering.

                PollEvents();

                _<SceneManager>().UpdateCurrentScene();

                _<FPSCounter>().Update();
            }

            std::cout << "Exiting game." << std::endl;
        }
        catch (const std::exception &e)
        {
            std::cout << "Caught exception: " << e.what() << std::endl;
        }
    }

    void Engine::Randomize()
    {
        srand(time(nullptr));
    }

    void Engine::PollEvents()
    {
        SDL_Event event;

        while (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
            case SDL_QUIT:
                m_running = false;
                break;
            case SDL_KEYDOWN:
                _<KeyboardInput>().RegisterKeyPress(event.key.keysym.sym);
                break;
            case SDL_KEYUP:
                _<KeyboardInput>().RegisterKeyRelease(event.key.keysym.sym);
                break;
            case SDL_MOUSEBUTTONDOWN:
                _<MouseInput>().RegisterButtonPress(event.button.button);
                break;
            case SDL_MOUSEBUTTONUP:
                _<MouseInput>().RegisterButtonRelease(event.button.button);
                break;
            }
        }
    }
}