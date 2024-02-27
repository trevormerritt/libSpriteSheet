// Copyright 2024 <Trevor Merritt>
#pragma once

#include "imgui.h"
#include <string>

namespace SpriteSheet {
    /**
     * @brief A Single sprite on the screen
     *
     */
    class Sprite {
        public:
        /**
         * @brief Construct a new Sprite object
         *
         * @param coordinates Origin and Limit for Sprite on Texture in Pixels
         * @param textureSize Size of Texture in Pixels
         */
            Sprite(ImVec4 *coordinates, ImVec2 *textureSize) { _coordinates = coordinates; _textureSize = textureSize; }
            /**
             * @brief Returns normalized texture coordinates for the sprite
             *
             * @return ImVec4* Normalized Origin and Limit for sprite on Texture
             */
            ImVec4 *textureCoordinates();
            /**
             * @brief Size of the image scaled per parameter
             *
             * @param scale X and Y scale.  Defaults to 1.0, 1.0
             * @return ImVec2* Scaled size in Pixels
             */
            ImVec2 *scaledSize(ImVec2 *scale = new ImVec2(1.0f, 1.0f));

            std::string *serialize();
            Sprite& deserialize(std::string *toDeserialize, ImVec2 *textureSize);

        private:
            ImVec4 *_coordinates;
            ImVec2 *_textureSize;
    };
}
