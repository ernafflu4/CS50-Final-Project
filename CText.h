#ifndef _CTEXT_H_
    #define _CTEXT_H_

#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>
#include <string>
#include <cmath>

#include "CTexture.h"

class CText{
    public:
        CText();
    public:
        static SDL_Texture* Load(SDL_Renderer* Rend, const char* Text);
        static bool DrawMessage(SDL_Renderer* Rend, SDL_Texture* Texture);
};

#endif
