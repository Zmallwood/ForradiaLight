/*
 * Copyright 2026 Andreas Åkerberg
 * This code is licensed under MIT license (see LICENSE for details)
 */

#pragma once

#include <iostream>
#include <memory>
#include <map>
#include <string>
#include <filesystem>
#include <algorithm>
#include <set>
#include <vector>
#include <unordered_map>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

#include "Common/Singleton.hpp"
#include "Common/SDLDeleter.hpp"
#include "Common/Hash.hpp"
#include "Common/Matter/Size.hpp"
#include "Common/Matter/SizeF.hpp"
#include "Common/Matter/Point.hpp"
#include "Common/Matter/PointF.hpp"
#include "Common/Matter/Color.hpp"
#include "Common/Utilities.hpp"
#include "Common/Constants.hpp"