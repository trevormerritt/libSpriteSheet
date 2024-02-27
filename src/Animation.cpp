// Copyright 2024 <Trevor Merritt>
#include "include/Animation.hpp"

namespace SpriteSheet
{
    Animation::Animation(std::vector<AnimationFrame> *framesAndTimes) {
        _framesAndTimes = framesAndTimes;
    };

    Animation &Animation::addFrame(Sprite *sprite, int duration)
    {
        auto newAnimation = new AnimationFrame(*sprite, duration);
        _framesAndTimes->push_back(*newAnimation);
        return *this;
    };
}
