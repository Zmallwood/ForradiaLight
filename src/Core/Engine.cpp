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

namespace Forra
{
    void Engine::Run()
    {
        try
        {
            Randomize();

            _<SDLDevice>().Initialize();

            _<ImageBank>().LoadImages();

            _<Cursor>().Initialize();

            while (m_running)
            {
                PollEvents();

                _<SceneManager>().UpdateCurrentScene();

                _<SDLDevice>().ClearCanvas();

                _<SceneManager>().RenderCurrentScene();

                _<Cursor>().Render();

                _<SDLDevice>().PresentCanvas();
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