#ifndef _CGAME_H_
    #define _CGAME_H_

#include <SDL2/SDL.h>

#include "Define.h"
#include "CEvent.h"
#include "CTexture.h"
#include "CTile.h"
#include "CMap.h"
#include "CCamera.h"
#include "CAnimation.h"
#include "CEntity.h"
#include "CPlayer.h"
#include "CText.h"

class CGame : public CEvent {
    private:
        bool Running;
        SDL_Window* Window;
        SDL_Surface* Surface;
        SDL_Renderer* Rend;
        SDL_Renderer* TextRend;
        SDL_Texture* Texture;
        SDL_Texture* TT;
        TTF_Font* Font;
    private:
        CEntity Test;
        CEntity Malan;
        CEntity Tree;
        CEntity Tree2;
        CEntity Tree3;
        CEntity Tree4;
        CEntity House1;
        CEntity House2;
        CEntity House3;
        CEntity House4;
        CEntity Cat1;
        CEntity Cat2;
        CEntity Yoshi2;
        CEntity Yoshi3;
        CEntity Yoshi4;
    private:
        CPlayer Player;
    public:
        CGame();
        int OnExecute();
    public:
        bool OnInit();
        void OnEvent(SDL_Event* Event);
        void OnExit();
        void OnLoop();
        void OnRender();
        void OnCleanup();
        void OnKeyDown(SDL_Keycode sym, Uint16 mod, Uint16 scancode);
        void OnKeyUp(SDL_Keycode sym, Uint16 mod, Uint16 scancode);
};

#endif
