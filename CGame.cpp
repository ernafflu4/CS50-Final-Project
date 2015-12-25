#include "CGame.h"

CGame::CGame()
{
    Window = NULL;
    Rend = NULL;
    TextRend = NULL;
    Running = true;
    TT = NULL;
}

int CGame::OnExecute()
{
    if (OnInit() == false)
    {
        return -1;
    }
    
    SDL_Event Event;
    while(Running)
    {
        while(SDL_PollEvent(&Event))
        {
            OnEvent(&Event);
        }
        OnLoop();
        OnRender();
    }
    OnCleanup();
    return 0;
}

int main(int argc, char* argv[])
{
    CGame VideoGame;
    return VideoGame.OnExecute();
}

