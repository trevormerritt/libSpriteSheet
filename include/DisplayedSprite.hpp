// Copyright 2024 <Trevor Merritt>
#pragma once

#include "imgui.h"

namespace SpriteSheet
{
    class DisplayedSprite
    {
    public:
        DisplayedSprite(int spriteIndex, ImVec2 *origin, ImVec2 *scale);
        DisplayedSprite &hide();
        DisplayedSprite &show();
        DisplayedSprite &move(ImVec2 *relativeDistance);
        DisplayedSprite &moveAbsolute(ImVec2 *absoluteLocation);

    private:
        ImVec2 *_origin;
        ImVec2 *_scale = new ImVec2(1.0f, 1.0f);
        int _spriteIndex = 0;
        bool visible = true;
    };
};
