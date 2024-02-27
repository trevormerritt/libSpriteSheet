// Copyright 2024 <Trevor Merritt>
#include <iostream>

#include "include/Constants.hpp"
#include "include/Sprite.hpp"
#include "json/json.h"

namespace SpriteSheet
{

    ImVec2 *Sprite::scaledSize(ImVec2 *scale)
    {
        return new ImVec2(
            scale->x * (_coordinates->z - _coordinates->x),
            scale->y * (_coordinates->w - _coordinates->y));
    };

    ImVec4 *Sprite::textureCoordinates()
    {
        return new ImVec4(
            _coordinates->x / _textureSize->x, _coordinates->y / _textureSize->y,
            _coordinates->z / _textureSize->x, _coordinates->w / _textureSize->y);
    };

    Sprite &Sprite::deserialize(std::string *toDeserialize, ImVec2 *textureSize)
    {
        Json::Value toParse = Json::Value(toDeserialize);
        std::cout << "Preparing to parse " << toParse << std::endl;
        int newOriginX = toParse[SPRITEMAP_ORIGINX_LABEL].asInt();
        int newOriginY = toParse[SPRITEMAP_ORIGINY_LABEL].asInt();
        int newLimitX = toParse[SPRITEMAP_LIMITX_LABEL].asInt();
        int newLimitY = toParse[SPRITEMAP_LIMITY_LABEL].asInt();
        _coordinates->x = newOriginX;
        _coordinates->y = newOriginY;
        _coordinates->z = newLimitX;
        _coordinates->w = newLimitY;
        _textureSize = textureSize;
        return *this;
    }

    std::string *Sprite::serialize()
    {
        Json::Value toReturn;
        toReturn[SPRITEMAP_ORIGINX_LABEL] = _coordinates->x;
        toReturn[SPRITEMAP_ORIGINY_LABEL] = _coordinates->y;
        toReturn[SPRITEMAP_LIMITX_LABEL] = _coordinates->z;
        toReturn[SPRITEMAP_LIMITY_LABEL] = _coordinates->w;
        std::string returnValue = toReturn.asString().c_str();
        return &returnValue;
    }
};
