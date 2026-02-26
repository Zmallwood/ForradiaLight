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
            Log("Starting engine.", LogLevels::Info);

            Randomize();

            _<SDLDevice>().Initialize();

            _<ImageBank>().LoadImages();

            _<TextRenderer>().Initialize();

            _<Cursor>().Initialize();

            Log("Entering main loop.", LogLevels::Info);

            while (m_running)
            {
                _<Cursor>().Reset();

                Log("Polling events.", LogLevels::Info);

                PollEvents();

                Log("Updating current scene.", LogLevels::Info);

                _<SceneManager>().UpdateCurrentScene();

                Log("Updating FPS counter.", LogLevels::Info);

                _<FPSCounter>().Update();

                Log("Clearing canvas.", LogLevels::Info);

                _<SDLDevice>().ClearCanvas();

                Log("Rendering current scene.", LogLevels::Info);

                _<SceneManager>().RenderCurrentScene();

                Log("Rendering FPS counter.", LogLevels::Info);

                _<FPSCounter>().Render();

                Log("Rendering cursor.", LogLevels::Info);

                _<Cursor>().Render();

                Log("Presenting canvas.", LogLevels::Info);

                _<SDLDevice>().PresentCanvas();
            }

            Log("Cleaning up cursor.", LogLevels::Info);

            _<Cursor>().Cleanup();

            Log("Cleaning up SDL device.", LogLevels::Info);

            _<SDLDevice>().Cleanup();

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