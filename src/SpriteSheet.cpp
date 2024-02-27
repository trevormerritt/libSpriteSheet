// Copyright 2024 <Trevor Merritt>
#include "include/SpriteSheet.hpp"

#include <fstream>
#include <iostream>

#include "include/ImageUtils.hpp"
#define STB_IMAGE_IMPLEMENTATION

namespace SpriteSheet
{
    SpriteSheet &SpriteSheet::setImageFilename(std::string *newImageFilename, bool autoLoad) {
        _imageFilename = newImageFilename;
        // Build the '.spritesheet' filename.
        if (autoLoad) {
            loadSpriteSheet();
        }
        return *this;
    }

    void SpriteSheet::loadSpriteSheet() {
        // Load the spritesheet image and its related meta-data

        bool loadResult = Util::loadTextureFromFile(_imageFilename->c_str(), imageTexture, _textureSize);

        if (loadResult) {
            // Horray!  we loaded the image.
            _hasLoadedImage = true;

            // Now find and load the '.spritesheet' file
            loadMetadata();
        };
    }

    SpriteSheet &SpriteSheet::addSprite(Sprite *toAdd) {
        _sprites->push_back(*toAdd);
        return *this;
    }

    SpriteSheet &SpriteSheet::addAnimation(Animation *toAdd) {
        _animations->push_back(*toAdd);
        return *this;
    }

    void SpriteSheet::loadMetadata() {
        // A Spritesheet has:
        // Title.
        // Texture Size
        // 0+ Sprites
        // 0+ Animations
        std::fstream file(spritesheetFilename()->c_str());

        if (!file.is_open()) {
            std::cout << "Unable to open spritesheet." << std::endl;
            return;
        }
        std::string line;
        while(std::getline(file, line)) {

        }
    }

    void SpriteSheet::reloadMetadata() {
        loadMetadata();
    }
}
