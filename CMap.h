#ifndef _CMAP_H_
    #define _CMAP_H_
    
#include <SDL2/SDL.h>
#include <vector>

#include "CTile.h"
#include "CTexture.h"

class CMap {
    public:
        static CMap MapControl;
    public:
        SDL_Surface* Surf_Tileset;
        SDL_Texture* Tex_Tileset;
        int MapSize;
    private:
        std::vector<CTile> TileList;
    public:
        CMap();
    public:
        bool OnLoad(SDL_Renderer* Rend, char* MapFile, char* TileFile);
        void OnRender(SDL_Renderer* Rend, SDL_Surface* Surface, int MapX, int MapY);
        void OnRender(SDL_Renderer* Rend, SDL_Texture* Texture, int MapX, int MapY);
        void OnCleanup();
    public:
        CTile* GetTile(int X, int Y); 
};

#endif
