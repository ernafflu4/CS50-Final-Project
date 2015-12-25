#include "CText.h"

CText::CText() {
}

SDL_Texture* CText::Load(SDL_Renderer* Rend, const char* Text) {
    TTF_Font* Font = NULL;
    SDL_Surface* Surface = NULL;
    SDL_Texture* Texture = NULL;
    
    if ((Font = TTF_OpenFont("fonts/sansserifnarrowbold.ttf", 28)) == NULL)
    {
        return NULL;
    }
    
    SDL_Color TextColor = {0, 0, 0};
    
    if ((Surface = TTF_RenderText_Solid(Font, Text, TextColor)) == NULL)
    {
        return NULL;
    }
    
    if ((Texture = CTexture::S2T(Rend, Surface)) == NULL)
    {
        return NULL;
    }
    
    return Texture;
}

bool DrawMessage(SDL_Renderer* Rend, SDL_Texture* Texture)
{
    if (Rend == NULL || Texture == NULL)
    {
        return false;
    }
    
    CTexture::OnDraw(Rend, Texture, 320, 400);
    
    return true;
}
