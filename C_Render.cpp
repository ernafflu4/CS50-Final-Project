#include "CGame.h"

void CGame::OnRender() {
    // Map
    CMap::MapControl.OnRender(Rend, Texture, -CCamera::CameraControl.GetX(), -CCamera::CameraControl.GetY());
    
    
    
    // All Entitites, including Player
    for(int i = 0;i < CEntity::EntityList.size();i++) 
    {
        if(!CEntity::EntityList[i]) continue;
 
        CEntity::EntityList[i]->OnRender(Rend);
    }
    
    SDL_RenderPresent(Rend);
}
