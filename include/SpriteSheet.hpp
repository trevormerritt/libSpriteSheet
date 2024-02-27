// Copyright 2024 <Trevor Merritt>
#pragma once

#include <string>
#include <vector>
#include "imgui.h"
#include "include/Sprite.hpp"
#include "include/Animation.hpp"
#include "ext/stb_image.h"
#include <GL/gl.h>

namespace SpriteSheet
{
    /**
     * @brief A single Image File that contains multiple smaller pictures
     *
     */
    class SpriteSheet
    {
    public:
        SpriteSheet(){};
        /**
         * @brief Set the Image Filename
         *
         * @param newImageFilename Name of the File
         * @return SpriteSheet&
         */
        SpriteSheet &setImageFilename(std::string *newImageFilename, bool autoLoad = true);

        /**
         * @brief Add a Sprite to the SpriteSheet
         *
         * @param toAdd
         * @return SpriteSheet&
         */
        SpriteSheet &addSprite(Sprite *toAdd);

        /**
         * @brief Add an Animation to the SpriteSheet
         *
         * @param toAdd Animation to Add
         * @return SpriteSheet& SpriteSheet with new Animation added
         */
        SpriteSheet &addAnimation(Animation *toAdd);

        bool loadedImage() { return _hasLoadedImage; }
        bool loadedSprites() { return _hasLoadedSprites; }
        bool loadedAnimations() { return _hasLoadedAnimations; }
        ImVec2 *textureSize() { return _textureSize; };
        std::string *imageFilename() { return _imageFilename; }
        std::string *spritesheetFilename() {
            return new std::string(imageFilename()->append(".spritesheet"));
         }

        ImVec4 *spriteAt(ImVec2 *origin = new ImVec2(0, 0), ImVec2 *limit = new ImVec2(-1.0f, -1.0f), ImVec2 *scale = new ImVec2(1.0f, 1.0f))
        {
            return new ImVec4(
                origin->x,
                origin->y,
                (((limit->x == -1) ? _textureSize->x : limit->x) * scale->x),
                (((limit->y == -1) ? _textureSize->y : limit->y) * scale->y));
        };
        ImTextureID *texture() {
            return (ImTextureID *)imageTexture;
        };
        void reloadMetadata();
    private:
        void loadSpriteSheet();
        void loadMetadata();
        bool _hasLoadedImage = false;
        bool _hasLoadedSprites = false;
        bool _hasLoadedAnimations = false;
        std::string *_imageFilename = new std::string("");
        std::string *_spritesheetFilename = new std::string("");
        ImVec2 *_textureSize = new ImVec2(0, 0);
        std::vector<Sprite> *_sprites = new std::vector<Sprite>();
        std::vector<Animation> *_animations = new std::vector<Animation>();
        GLuint *imageTexture;
    };
};
