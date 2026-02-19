/*
 * Copyright 2026 Andreas Åkerberg
 * This code is licensed under MIT license (see LICENSE for details)
 */

#include "WorldGenerator.hpp"
#include "Core/WorldStructure/World.hpp"
#include "Core/WorldStructure/WorldArea.hpp"
#include "Core/WorldStructure/Tile.hpp"
#include "Core/WorldStructure/ObjectsStack.hpp"

namespace Forradia
{
    void WorldGenerator::GenerateNewWorld()
    {
        ClearWorldWithGrass();

        GenerateDirt();

        GenerateRock();

        GenerateWater();

        GeneratObjects();
    }

    void WorldGenerator::ClearWorldWithGrass()
    {
        auto worldArea{_<World>().GetCurrentWorldArea()};

        if (!worldArea)
        {
            throw std::runtime_error(
                "WorldGenerator: Current world area doesn't exist to clear with grass.");
        }

        auto size{worldArea->GetSize()};

        for (auto y = 0; y < size.height; y++)
        {
            for (auto x = 0; x < size.width; x++)
            {
                if (!worldArea->IsValidTile(x, y))
                {
                    continue;
                }

                auto tile{worldArea->GetTile(x, y)};

                tile->SetGround("KatenaNumbra");
            }
        }
    }

    void WorldGenerator::GenerateDirt()
    {
        auto worldArea{_<World>().GetCurrentWorldArea()};

        if (!worldArea)
        {
            throw std::runtime_error(
                "WorldGenerator: Current world area doesn't exist to generate dirt.");
        }

        auto size{worldArea->GetSize()};

        auto numDirtAreas{30};

        for (auto i = 0; i < numDirtAreas; i++)
        {
            auto xCenter{rand() % size.width};
            auto yCenter{rand() % size.height};
            auto radius{rand() % 3 + 5};

            for (auto x = xCenter - radius; x <= xCenter + radius; x++)
            {
                for (auto y = yCenter - radius; y <= yCenter + radius; y++)
                {
                    if (!worldArea->IsValidTile(x, y))
                    {
                        continue;
                    }

                    auto dx{x - xCenter};
                    auto dy{y - yCenter};

                    if (dx * dx + dy * dy > radius * radius)
                    {
                        continue;
                    }

                    auto tile{worldArea->GetTile(x, y)};

                    tile->SetGround("GroundDirt");
                }
            }
        }
    }

    void WorldGenerator::GenerateRock()
    {
        auto worldArea{_<World>().GetCurrentWorldArea()};

        if (!worldArea)
        {
            throw std::runtime_error(
                "WorldGenerator: Current world area doesn't exist to generate dirt.");
        }

        auto size{worldArea->GetSize()};

        auto numRockAreas{30};

        for (auto i = 0; i < numRockAreas; i++)
        {
            auto xCenter{rand() % size.width};
            auto yCenter{rand() % size.height};
            auto radius{rand() % 3 + 5};

            for (auto x = xCenter - radius; x <= xCenter + radius; x++)
            {
                for (auto y = yCenter - radius; y <= yCenter + radius; y++)
                {
                    if (!worldArea->IsValidTile(x, y))
                    {
                        continue;
                    }

                    auto dx{x - xCenter};
                    auto dy{y - yCenter};

                    if (dx * dx + dy * dy > radius * radius)
                    {
                        continue;
                    }

                    auto tile{worldArea->GetTile(x, y)};

                    tile->SetGround("GroundRock");
                }
            }
        }
    }

    void WorldGenerator::GenerateWater()
    {
        auto worldArea{_<World>().GetCurrentWorldArea()};

        if (!worldArea)
        {
            throw std::runtime_error(
                "WorldGenerator: Current world area doesn't exist to generate water.");
        }

        auto size{worldArea->GetSize()};

        auto numLakes{20};

        for (auto i = 0; i < numLakes; i++)
        {
            auto xCenter{rand() % size.width};
            auto yCenter{rand() % size.height};
            auto radius{rand() % 10 + 5};

            for (auto x = xCenter - radius; x <= xCenter + radius; x++)
            {
                for (auto y = yCenter - radius; y <= yCenter + radius; y++)
                {
                    if (!worldArea->IsValidTile(x, y))
                    {
                        continue;
                    }

                    auto dx{x - xCenter};
                    auto dy{y - yCenter};

                    if (dx * dx + dy * dy > radius * radius)
                    {
                        continue;
                    }

                    auto tile{worldArea->GetTile(x, y)};

                    tile->SetGround("GroundWater");
                }
            }
        }
    }

    void WorldGenerator::GeneratObjects()
    {
        auto worldArea{_<World>().GetCurrentWorldArea()};

        if (!worldArea)
        {
            throw std::runtime_error(
                "WorldGenerator: Current world area doesn't exist to generate objects.");
        }

        auto size{worldArea->GetSize()};

        auto numTree1s{200};

        for (auto i = 0; i < numTree1s; i++)
        {
            auto x{rand() % size.width};
            auto y{rand() % size.height};

            if (!worldArea->IsValidTile(x, y))
            {
                continue;
            }

            auto tile{worldArea->GetTile(x, y)};

            if (tile->GetGround() == Hash("KatenaNumbra"))
            {
                auto objectsStack{tile->GetObjectsStack()};

                if (!objectsStack)
                {
                    throw std::runtime_error("WorldGenerator: Objects stack doesn't exist.");
                }

                objectsStack->AddObject("ObjectTree1");
            }
        }

        auto numTree2s{200};

        for (auto i = 0; i < numTree2s; i++)
        {
            auto x{rand() % size.width};
            auto y{rand() % size.height};

            if (!worldArea->IsValidTile(x, y))
            {
                continue;
            }

            auto tile{worldArea->GetTile(x, y)};

            if (tile->GetGround() == Hash("KatenaNumbra"))
            {
                auto objectsStack{tile->GetObjectsStack()};

                if (!objectsStack)
                {
                    throw std::runtime_error("WorldGenerator: Objects stack doesn't exist.");
                }

                objectsStack->AddObject("ObjectTree2");
            }
        }

        auto numObject1s{200};

        for (auto i = 0; i < numObject1s; i++)
        {
            auto x{rand() % size.width};
            auto y{rand() % size.height};

            if (!worldArea->IsValidTile(x, y))
            {
                continue;
            }

            auto tile{worldArea->GetTile(x, y)};

            if (tile->GetGround() == Hash("KatenaNumbra"))
            {
                auto objectsStack{tile->GetObjectsStack()};

                if (!objectsStack)
                {
                    throw std::runtime_error("WorldGenerator: Objects stack doesn't exist.");
                }

                objectsStack->AddObject("ObjectBush1");
            }
        }

        auto numStoneBoulders{200};

        for (auto i = 0; i < numStoneBoulders; i++)
        {
            auto x{rand() % size.width};
            auto y{rand() % size.height};

            if (!worldArea->IsValidTile(x, y))
            {
                continue;
            }

            auto tile{worldArea->GetTile(x, y)};

            auto objectsStack{tile->GetObjectsStack()};

            if (!objectsStack)
            {
                throw std::runtime_error("WorldGenerator: Objects stack doesn't exist.");
            }

            objectsStack->AddObject("ObjectStoneBoulder");
        }
    }
}