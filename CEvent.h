#ifndef _CEVENT_H_
    #define _CEVENT_H_
    
#include <SDL2/SDL.h>

class CEvent {
    public:
    
        CEvent();
        
        virtual ~CEvent();
        
        virtual void OnEvent(SDL_Event* Event);
        
        virtual void OnExit();
        
        virtual void OnKeyDown(SDL_Keycode sym, Uint16 mod, Uint16 scancode);
        
        virtual void OnKeyUp(SDL_Keycode sym, Uint16 mod, Uint16 scancode);
        
        virtual void OnWindowResized(int data1, int data2);
        
        virtual void OnUser(Uint8 type, int code, void* data1, void* data2);
};
#endif
