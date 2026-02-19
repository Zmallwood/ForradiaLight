/*
 * Copyright 2026 Andreas Åkerberg
 * This code is licensed under MIT license (see LICENSE for details)
 */

#include "WorldView.hpp"
#include "Core/Rendering/ImageRenderer.hpp"
#include "Core/WorldStructure/World.hpp"
#include "Core/WorldStructure/WorldArea.hpp"
#include "Core/WorldStructure/Tile.hpp"
#include "Core/WorldStructure/ObjectsStack.hpp"
#include "Core/WorldStructure/Object.hpp"
#include "Theme0/Theme0Math/TileGridMath.hpp"
#include "Core/CoreGameObjects/Player.hpp"
#include "Core/Assets/ImageBank.hpp"
#include "Theme0/Scenes/Main/Sub/TileHovering.hpp"

namespace Forradia
{
    void WorldView::Render() const
    {
        auto currentWorldArea = _<World>().GetCurrentWorldArea();

        if (!currentWorldArea)
        {
            throw std::runtime_error("WorldView: Current world area doesn't exist.");
        }

        auto tileGridSize{CalcTileGridSize()};

        if (tileGridSize.width == 0 || tileGridSize.height == 0)
        {
            throw std::runtime_error("WorldView: Tile grid size has a dimension of 0.");
        }

        auto tileSize{CalcTileSize()};

        auto smallValue{k_smallValue};

        auto playerPosition{_<Player>().GetPosition()};

        auto canvasSize{GetCanvasSize()};

        auto hoveredCoordinate{_<TileHovering>().GetHoveredCoordinate()};

        for (auto y = 0; y < tileGridSize.height; y++)
        {
            for (auto x = 0; x < tileGridSize.width; x++)
            {
                auto xCoordinate{playerPosition.x - (tileGridSize.width - 1) / 2 + x};
                auto yCoordinate{playerPosition.y - (tileGridSize.height - 1) / 2 + y};

                if (!currentWorldArea->IsValidTile(xCoordinate, yCoordinate))
                {
                    continue;
                }

                auto tile{currentWorldArea->GetTile(xCoordinate, yCoordinate)};

                auto ground{tile->GetGround()};

                if (ground == Hash("GroundWater"))
                {
                    std::string imageName{"GroundWater_"};

                    auto waterAnimIndex{SDL_GetTicks() / 100 % 3};

                    imageName += std::to_string(waterAnimIndex);

                    ground = Hash(imageName);
                }

                _<ImageRenderer>().DrawImage(ground, x * tileSize.width, y * tileSize.height,
                                             tileSize.width + smallValue,
                                             tileSize.height + smallValue);

                auto darknessLevel{tile->GetDarknessLevel()};

                for (auto i = 0; i < darknessLevel; i++)
                {
                    _<ImageRenderer>().DrawImage("TransparentBlack", x * tileSize.width,
                                                 y * tileSize.height, tileSize.width + smallValue,
                                                 tileSize.height + smallValue);
                }

                if (xCoordinate == hoveredCoordinate.x && yCoordinate == hoveredCoordinate.y)
                {
                    _<ImageRenderer>().DrawImage("TileHovered", x * tileSize.width,
                                                 y * tileSize.height, tileSize.width + smallValue,
                                                 tileSize.height + smallValue);
                }

                auto objectsStack{tile->GetObjectsStack()};

                if (!objectsStack)
                {
                    throw std::runtime_error("WorldView: Objects stack doesn't exist.");
                }

                for (auto object : objectsStack->GetObjects())
                {
                    if (!object)
                    {
                        throw std::runtime_error("WorldView: Object doesn't exist.");
                    }

                    auto imageSize{_<ImageBank>().GetImageSize(object->GetType())};

                    if (imageSize.width == 0 || imageSize.height == 0)
                    {
                        throw std::runtime_error("WorldView: Image size has a dimension of 0.");
                    }

                    auto imageWidth{static_cast<float>(imageSize.width) / 60.0f * tileSize.width};
                    auto imageHeight{static_cast<float>(imageSize.height) / 60.0f *
                                     tileSize.height};

                    auto imageX{x * tileSize.width + (tileSize.width - imageWidth) / 2};
                    auto imageY{y * tileSize.height + tileSize.height - imageHeight};

                    _<ImageRenderer>().DrawImage(object->GetType(), imageX, imageY, imageWidth,
                                                 imageHeight);
                }

                if (xCoordinate == playerPosition.x && yCoordinate == playerPosition.y)
                {
                    _<ImageRenderer>().DrawImage("Kazek", x * tileSize.width, y * tileSize.height,
                                                 tileSize.width + smallValue,
                                                 tileSize.height + smallValue);
                }
            }
        }
    }
}