#ifndef _CANIMATION_H_
    #define _CANIMATION_H_
    
#include <SDL2/SDL.h>

class CAnimation {
    private:
        int CurrentFrame;
        int FrameInc;
    private:
        int FrameRate; // in milliseconds
        long OldTime;
    public:
        int MaxFrames;
        bool Oscillate;
    public:
        CAnimation();
        void OnAnimate();
    public:
        void SetFrameRate(int Rate);
        void SetCurrentFrame(int Frame);
        int GetCurrentFrame();
};
    
#endif
