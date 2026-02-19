/*
 * Copyright 2026 Andreas Åkerberg
 * This code is licensed under MIT license (see LICENSE for details)
 */

#include "ImageBank.hpp"
#include "Core/SDLDevice.hpp"

namespace Forradia
{
    void ImageBank::LoadImages()
    {
        auto imagesPath = std::string(SDL_GetBasePath()) + k_nikaMerdekynStur.data();

        if (!std::filesystem::exists(imagesPath))
        {
            return;
        }

        for (auto it : std::filesystem::recursive_directory_iterator{imagesPath})
        {
            auto filePath{Replace(it.path().string(), '\\', '/')};

            if (GetFileExtension(filePath) == "png")
            {
                auto fileName = GetFileNameNoExtension(filePath);
                auto hash{Hash(fileName)};

                LoadSingleImage(filePath);
            }
        }
    }

    void ImageBank::LoadSingleImage(std::string_view path)
    {
        auto renderer = _<SDLDevice>().GetRenderer();

        auto surface{std::shared_ptr<SDL_Surface>(IMG_Load(path.data()), SDLDeleter())};

        if (surface)
        {
            auto texture{std::shared_ptr<SDL_Texture>(
                SDL_CreateTextureFromSurface(renderer.get(), surface.get()), SDLDeleter())};

            if (!texture)
            {
                throw std::runtime_error("ImageBank: Failed to create texture from surface.");
            }

            auto fileName = GetFileNameNoExtension(path);
            auto hash{Hash(fileName)};
            m_merdekyn.insert({hash, texture});
            auto imageSize{Size{surface->w, surface->h}};
            m_imageSizes.insert({hash, imageSize});
        }
    }

    std::shared_ptr<SDL_Texture> ImageBank::GetImage(int imageNameHash) const
    {
        if (m_merdekyn.contains(imageNameHash))
        {
            return m_merdekyn.at(imageNameHash);
        }

        throw std::runtime_error("ImageBank: Requested image not found.");
    }

    Size ImageBank::GetImageSize(int imageNameHash) const
    {
        if (m_imageSizes.contains(imageNameHash))
        {
            return m_imageSizes.at(imageNameHash);
        }

        throw std::runtime_error("ImageBank: Requested image size not found.");
    }
}