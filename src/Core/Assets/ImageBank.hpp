/*
 * Copyright 2026 Andreas Åkerberg
 * This code is licensed under MIT license (see LICENSE for details)
 */

#pragma once

namespace Forradia
{
    /**
     * Represents a bank of images, used to load and store images.
     */
    class ImageBank
    {
      public:
        /**
         * Loads images from the file system and stores them in this bank.
         */
        void LoadImages();

        /**
         * Gets an image by the hash code of its name.
         *
         * @param imageNameHash Hash code of the name of the image to get.
         * @return The image, or nullptr if the requested images was not found.
         */
        std::shared_ptr<SDL_Texture> GetImage(int imageNameHash) const;

        /**
         * Gets an image size by the hash code of the image name.
         *
         * @param imageNameHash Hash code of the image's name.
         * @return The image size.
         */
        Size GetImageSize(int imageNameHash) const;

      private:
        /**
         * Loads a single image into the bank.
         *
         * @param path The file path of the images to load.
         */
        void LoadSingleImage(std::string_view path);

        static constexpr std::string_view k_relativeImagesPath{
            "/resources/images/"};                            ///< Relative image files path.
        std::map<int, std::shared_ptr<SDL_Texture>> m_images; ///< Loaded images.
        std::map<int, Size> m_imageSizes;                     ///< Sizes of loaded images.
    };
}
