#include "CTexture.h"

CTexture::CTexture() {
}

SDL_Surface* CTexture::OnLoad(char* File) {
    SDL_Surface* Surface = NULL;
    if ((Surface = IMG_Load(File)) == NULL)
    {
        return NULL;
    }
    return Surface;
}

bool CTexture::Transparent(SDL_Surface* Surface, int R, int G, int B) {
    if(Surface == NULL)
    {
        return false;
    }
    
    SDL_SetColorKey(Surface, SDL_RLEACCEL, SDL_MapRGB(Surface->format, R, G, B));
    
    return true;
}

SDL_Texture* CTexture::S2T(SDL_Renderer* Rend, SDL_Surface* Surface) {
    if (Rend == NULL || Surface == NULL)
    {
        return NULL;
    }
    SDL_Texture* Texture = NULL;
    if ((Texture = SDL_CreateTextureFromSurface(Rend, Surface)) == NULL)
    {
        return NULL;
    }
    SDL_FreeSurface(Surface);
    return Texture;
} 

SDL_Texture* CTexture::OnLoad(char* File, SDL_Renderer* Rend) {
    SDL_Texture* Texture = NULL;
    
    if ((Texture = IMG_LoadTexture(Rend, File)) == NULL)
    {
        return NULL;
    }
    
    return Texture;
}

bool CTexture::OnDraw(SDL_Renderer* Rend, SDL_Texture* Texture, int X, int Y) {
    if (Rend == NULL || Texture == NULL)
    {
        return false;
    }
    
    int img_width;
    int img_height;
    SDL_QueryTexture(Texture, NULL, NULL, &img_width, &img_height);
    
    SDL_Rect DestR;
    DestR.x = X;
    DestR.y = Y;
    DestR.w = img_width;
    DestR.h = img_height;
    
    SDL_RenderCopy(Rend, Texture, NULL, &DestR);
    
    return true;
}

bool CTexture::OnDraw(SDL_Renderer* Rend, SDL_Texture* Texture, int X, int Y, int X2, int Y2, int W2, int H2) {
    if (Rend == NULL || Texture == NULL)
    {
        return false;
    }
    
    int img_width;
    int img_height;
    SDL_QueryTexture(Texture, NULL, NULL, &img_width, &img_height);
    
    SDL_Rect DestR;
    DestR.x = X;
    DestR.y = Y;
    DestR.w = W2;
    DestR.h = H2;
    
    SDL_Rect SrcR;
    SrcR.x = X2;
    SrcR.y = Y2;
    SrcR.w = W2;
    SrcR.h = H2;
    
    SDL_RenderCopy(Rend, Texture, &SrcR, &DestR);
    
    return true;
}
