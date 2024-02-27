// Copyright 2024 <Trevor Merritt>
#pragma once

#include "imgui.h"
#include <json/json.h>


class SpriteRenderer;

/**
 * @brief A single sprite.
 *
 */
class Sprite
{
    friend SpriteRenderer;

public:
    /**
     * @brief Create a sprite from a JSON value
     */
    Sprite(Json::Value asJson, ImVec2 *textureLimit, ImTextureID *textureReference);
    Sprite(
        ImVec2 *spriteOrigin,
        ImVec2 *spriteLimit,
        ImVec2 *textureLimit,
        ImTextureID *textureReference);
    Json::Value *asJson();
    ImVec2 spriteSize();
    void render(
        ImVec2 *spriteOffset = new ImVec2(0, 0),
        ImVec2 *spriteScale = new ImVec2(1, 0));
    ImVec2 normalizedOrigin();
    ImVec2 normalizedLimit();
    ImVec2 origin();
    ImVec2 limit();
    std::string label();
    bool isValid();

protected:
    ImVec2 *_origin = new ImVec2(0, 0);
    ImVec2 *_limit = new ImVec2(0, 0);
    ImVec2 *_textureLimit = new ImVec2(0, 0);
    ImTextureID *_texture;

private:
    std::string *_labelText = new std::string("");
    void rebuildLabel();
};
