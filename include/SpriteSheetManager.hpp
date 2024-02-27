// Copyright 2024 <Trevor Merritt>
#pragma once

#include <string>
#include <vector>
#include "SpriteSheet.hpp"

namespace SpriteSheet {

    /**
     * @brief Singleton to handle loading SpriteSheets along with tracking which are
     * active, and where they are.
     *
     */
    class SpriteSheetManager {
        public:
            SpriteSheetManager();
            SpriteSheetManager& loadSpriteSheet(std::string *imageFilename, std::string *mappingName);
            void render();
        private:
            std::vector<SpriteSheet> *spriteSheets;
    };
};
