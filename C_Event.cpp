#include "CGame.h"

void CGame::OnEvent(SDL_Event* Event) {
    CEvent::OnEvent(Event);
}

void CGame::OnKeyDown(SDL_Keycode sym, Uint16 mod, Uint16 scancode) {
    switch(sym)
    {
        case SDLK_LEFT: {
            Player.MoveLeft = true;
            break;
        }
        case SDLK_RIGHT: {
            Player.MoveRight = true;
            break;
        }
        case SDLK_UP: {
            Player.MoveUp = true;
            break;
        }
        case SDLK_DOWN: {
            Player.MoveDown = true;
            break;
        }
        case SDLK_SPACE: {
            Player.SpaceDown = true;
        }
        default: {
        }
    }
}

void CGame::OnKeyUp(SDL_Keycode sym, Uint16 mod, Uint16 scancode) {
    switch(sym)
    {
        case SDLK_LEFT: {
            Player.MoveLeft = false;
            break;
        }
        case SDLK_RIGHT: {
            Player.MoveRight = false;
            break;
        }
        case SDLK_UP: {
            Player.MoveUp = false;
            break;
        }
        case SDLK_DOWN: {
            Player.MoveDown = false;
            break;
        }
        case SDLK_SPACE: {
            Player.SpaceDown = false;
        }
        default: {
        }
    }
}

void CGame::OnExit() {
    Running = false;
}
