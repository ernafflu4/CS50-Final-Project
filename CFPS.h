#ifndef _CFPS_H_
    #define _CFPS_H_

#include <SDL2/SDL.h>

class CFPS {
    public:
        static CFPS FPSControl;
    private:
        int OldTime; // used to calculate FPS
        int LastTime; // used to calculate SpeedFactor
        
        float SpeedFactor; //want movement to occur at the same speed on any computer
        
        int NumFrames; // current FPS
        int Frames;
    public:
        CFPS();
        void OnLoop();
    public:
        int GetFPS();
        float GetSpeedFactor();
};

#endif
