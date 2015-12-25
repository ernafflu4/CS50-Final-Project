#include "CPlayer.h"

CPlayer::CPlayer() {
}

bool CPlayer::OnLoad(SDL_Renderer* Rend, char* File, int Width, int Height, int MaxFrames) {
    if (CEntity::OnLoad(Rend, File, Width, Height, MaxFrames) == false)
    {
        return false;
    }
    
    return true;
}

void CPlayer::OnLoop() {
    CEntity::OnLoop();
}

void CPlayer::OnRender(SDL_Renderer* Rend) {
    CEntity::OnRender(Rend);
}

void CPlayer::OnCleanup() {
    CEntity::OnCleanup();
}

void CPlayer::OnAnimate() {
    if (SpeedX != 0 || SpeedY != 0)
    {
        Anim_Control.MaxFrames = 4;
    }
    else
    {
        Anim_Control.MaxFrames = 0;
    }
    
    CEntity::OnAnimate();
}

bool CPlayer::OnCollision(CEntity* Entity) {
    StopMove();
    CEntity::Print(Entity);
    return true;
}


