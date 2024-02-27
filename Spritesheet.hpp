// Copyright 2024 <Trevor Merritt>
#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "inc/model/Sprite.hpp"
#include "stb_image.h"
#include "imgui.h"
#include "glad/glad.h"

/**
 * @brief A Spritesheet.
 *
 * Handles loading/saving of an ini file that describes
 * the various sprites available in a similarly named file.
 *
 * ie: Character1Sprites.png
 *     Character1Sprites.spritesheetMap
 *
 */
class Spritesheet
{
public:
    Spritesheet(std::string *newImageFilename = new std::string(""));
    ImVec2 *imageSize(float scale = 1.0);
    GLuint imageTexture = 0;
    std::string loadedFilename() { return *imageFilename; };
    void deleteSpriteByIndex(int indexToDelete);
    void setImageFilename(std::string *newImageFilename);
    bool fileLoaded();
    void addNewSprite(Sprite *spriteToAdd);
    std::vector<ImVec4> *spriteSizes();
    std::vector<Sprite> *sprites = new std::vector<Sprite>();
    void load();
    void save();
    ImVec2 *textureSize() { return new ImVec2(width, height); }
private:
    int width = 0;
    int height = 0;
    bool mapLoaded = false;
    std::string *imageFilename = new std::string("");
    std::string *mapFilename = new std::string("");
    /**
     * loadTextureFromFile
     *
     * Load a texture from a file.  PNG, JPG, etc.
     *
     * @param filename char* Name of the file to load
     * @param out_texture GLuint* pointer for loaded texture
     * @param out_width integer for the width of the loaded image
     * @param out_height integer for the height of the loaded image
     */
    bool loadTextureFromFile(const char *filename, GLuint *out_texture, int *out_width, int *out_height);
};
