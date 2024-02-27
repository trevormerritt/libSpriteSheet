// Copyright 2024 <Trevor Merritt>
#pragma once

#include <utility>
#include <vector>
#include "include/Sprite.hpp"
#include "include/AnimationFrame.hpp"

namespace SpriteSheet
{
    /**
     * @brief A Series of sprites displayed sequentially to simulate motion
     *
     */
    class Animation
    {
    public:
        /**
         * @brief Construct a new Animation object
         *
         * @param framesAndTimes List of Frames and the times they are displayed
         */
        Animation(std::vector<AnimationFrame> *framesAndTimes);
        /**
         * @brief Add a Frame
         *
         * @param sprite Sprite to display for frame
         * @param duration Number of MS to display the frame for
         * @return Animation&
         */
        Animation &addFrame(Sprite *sprite, int duration);
    private:
        std::vector<AnimationFrame> *_framesAndTimes;
        int currentFrame = 0;
    };
};
