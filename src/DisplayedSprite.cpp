// Copyright 2024 <Trevor Merritt>
#include "include/DisplayedSprite.hpp"

namespace SpriteSheet
{
    DisplayedSprite &DisplayedSprite::moveAbsolute(ImVec2 *absoluteLocation)
    {
        _origin = absoluteLocation;
        return *this;
    };

    DisplayedSprite &DisplayedSprite::move(ImVec2 *relativeDistance)
    {
        _origin->x += relativeDistance->x;
        _origin->y += relativeDistance->y;
        return *this;
    };

    DisplayedSprite &DisplayedSprite::hide()
    {
        visible = false;
        return *this;
    }

    DisplayedSprite &DisplayedSprite::show()
    {
        visible = true;
        return *this;
    }

};
