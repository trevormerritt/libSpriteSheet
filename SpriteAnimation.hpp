// Copyright 2024 <Trevor Merritt>
#pragma once

#include <vector>
#include "inc/model/Sprite.hpp"

class SpriteAnimation {
public:
    SpriteAnimation();
    void render(ImVec2 *renderOrigin, float renderScale = 1.0) {};
private:
    std::vector<Sprite> *frames = new std::vector<Sprite>();
    // Number of MS to display the indexed frame.
    std::vector<std::pair<int, int>> *frameTiming = new std::vector<std::pair<int, int>>();

    // Index | Frame Number  |  Frame Timing
    //   1   |       1       |    100
    //   2   |       2       |    150
    //   3   |       3       |    100
    //   4   |       1       |    100
    //   5   |       2       |     50
    //   6   |       3       |    100
    //  ...
};
