#include "CGame.h"

void CGame::OnCleanup() {
    // Clean Entity Stuff
    for(int i = 0;i < CEntity::EntityList.size();i++) 
    {
        if(!CEntity::EntityList[i]) continue;
 
        CEntity::EntityList[i]->OnCleanup();
    }
 
    CEntity::EntityList.clear();
    // Map
    CMap::MapControl.OnCleanup();
    
    // Other Stuff
    SDL_DestroyTexture(Texture);
    SDL_DestroyRenderer(TextRend);
    SDL_DestroyRenderer(Rend);
    SDL_DestroyWindow(Window);
    SDL_Quit();
}
