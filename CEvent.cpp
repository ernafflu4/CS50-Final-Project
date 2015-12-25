#include "CEvent.h"

CEvent::CEvent() {
}

CEvent::~CEvent() {
}

void CEvent::OnEvent(SDL_Event* Event) {
    switch(Event->type)
    {
        case SDL_WINDOWEVENT:
        {
            switch(Event->window.event)
            {
                case SDL_WINDOWEVENT_RESIZED:
                {
                    OnWindowResized(Event->window.data1, Event->window.data2);
                    break;
                }
                case SDL_WINDOWEVENT_SHOWN:
				{
					break;
				}
				case SDL_WINDOWEVENT_HIDDEN:
				{
					break;
				}
				case SDL_WINDOWEVENT_EXPOSED:
				{
					break;
				}
				case SDL_WINDOWEVENT_MOVED:
				{
					break;
				}
				case SDL_WINDOWEVENT_SIZE_CHANGED:
				{
					break;
				}
				case SDL_WINDOWEVENT_MINIMIZED:
				{
					break;
				}
				case SDL_WINDOWEVENT_MAXIMIZED:
				{
					break;
				}
				case SDL_WINDOWEVENT_RESTORED:
				{
					break;
				}
				case SDL_WINDOWEVENT_CLOSE:
				{
					break;
				}
            }
            break;
        }
        case SDL_QUIT:
        {
            OnExit();
            break;
        }
        case SDL_KEYDOWN:
        {
            OnKeyDown(Event->key.keysym.sym,Event->key.keysym.mod,Event->key.keysym.scancode);
			break;
        }
        case SDL_KEYUP:
        {
            OnKeyUp(Event->key.keysym.sym,Event->key.keysym.mod,Event->key.keysym.scancode);
			break;
        }
        default:
        {
            OnUser(Event->user.type, Event->user.code, Event->user.data1, Event->user.data2);
			break;
        }
    }
}

void CEvent::OnExit() {
}

void CEvent::OnKeyDown(SDL_Keycode sym, Uint16 mod, Uint16 scancode) {
}

void CEvent::OnKeyUp(SDL_Keycode sym, Uint16 mod, Uint16 scancode) {
}

void CEvent::OnWindowResized(int data1, int data2) {
}

void CEvent::OnUser(Uint8 type, int code, void* data1, void* data2) {
}
