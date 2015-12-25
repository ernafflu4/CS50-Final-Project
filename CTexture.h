#ifndef _CTEXTURE_H_
    #define _CTEXTURE_H_

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class CTexture {
    public:
        CTexture();
    public:
        // Functions to load surface, make transparent, then convert to texture
        static SDL_Surface* OnLoad(char* File);
        static bool Transparent(SDL_Surface* Surface, int R, int G, int B);
        static SDL_Texture* S2T(SDL_Renderer* Rend, SDL_Surface* Surface);
        // Directly load texture
        static SDL_Texture* OnLoad(char* File, SDL_Renderer* Rend);
        // Draw the texture in the window (2nd fnc is for drawing a specific part of the texture)
        static bool OnDraw(SDL_Renderer* Rend, SDL_Texture* Texture, int X, int Y);
        static bool OnDraw(SDL_Renderer* Rend, SDL_Texture* Texture, int X, int Y, int X2, int Y2, int W2, int H2);        
};

#endif
