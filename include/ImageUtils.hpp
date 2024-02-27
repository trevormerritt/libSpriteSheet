// Copyright 2024 <Trevor Merritt>
#pragma once

#include "imgui.h"
#include <backends/imgui_impl_opengl2.h>

namespace SpriteSheet
{
    class Util
    {
    public:
        static bool loadTextureFromFile(const char *filename, GLuint *outTexture, ImVec2 *outSize)
        {
            printf("!! Loading texture [%s]\n", filename);
            int image_width = 0;
            int image_height = 0;
            int channels = 0;
            unsigned char *image_data = stbi_load(filename, &image_width, &image_height, &channels, 4);
            if (image_data == nullptr)
            {
                return false;
            }

#if SDL_BYTEORDER == SDL_BIG_ENDIAN
            uint32_t rmask = 0xff000000, gmask = 0x00ff0000, bmask = 0x0000ff00, amask = 0x000000ff;
#else // little endian, like x86, and typical desktop processors
            Uint32 rmask = 0x000000ff, gmask = 0x0000ff00, bmask = 0x00ff0000, amask = 0xff000000;
#endif

            GLuint image_texture;
            glGenTextures(1, &image_texture);
            glBindTexture(GL_TEXTURE_2D, image_texture);

            // Setup filtering parameters for display
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

            /*
            SDL_opengl2.h?
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S,
                            GL_CLAMP_TO_EDGE);                                   // This is required on WebGL for non power-of-two textures
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE); // Same
*/
            // Upload pixels into texture
#if defined(GL_UNPACK_ROW_LENGTH) && !defined(__EMSCRIPTEN__)
            glPixelStorei(GL_UNPACK_ROW_LENGTH, 0);
#endif
            glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, image_width, image_height, 0, GL_RGBA, GL_UNSIGNED_BYTE, image_data);
            stbi_image_free(image_data);

            *outTexture = image_texture;
            outSize = new ImVec2(image_width, image_height);
            printf("!! DONE LOADING TEXTURE\n");
            return true;
        }
    };

};
