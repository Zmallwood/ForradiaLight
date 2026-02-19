/*
 * Copyright 2026 Andreas Åkerberg
 * This code is licensed under MIT license (see LICENSE for details)
 */

#pragma once

namespace Forradia
{
    class ImageBank
    {
      public:
        void LoadImages();

        std::shared_ptr<SDL_Texture> GetImage(int imageNameHash) const;

        Size GetImageSize(int imageNameHash) const;

      private:
        void LoadSingleImage(std::string_view path);

        static constexpr std::string_view k_nikaMerdekynStur{"/resources/images/"};
        std::map<int, std::shared_ptr<SDL_Texture>> m_merdekyn;
        std::map<int, Size> m_imageSizes;
    };
}