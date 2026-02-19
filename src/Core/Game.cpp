/*
 * Copyright 2026 Andreas Åkerberg
 * This code is licensed under MIT license (see LICENSE for details)
 */

#include "Game.hpp"
#include "Engine.hpp"

namespace Forra
{
    void Game::Start()
    {
        _<Engine>().Run();
    }
}