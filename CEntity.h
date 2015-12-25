#ifndef _CENTITY_H_
    #define _CENTITY_H_

#include <vector>
#include <string>

#include "CAnimation.h"
#include "CTexture.h"
#include "CMap.h"
#include "CCamera.h"
#include "CFPS.h"
#include "CText.h"

enum {
    ENTITY_TYPE_GENERIC = 0,
    ENTITY_TYPE_PLAYER
};

enum {
    ENTITY_FLAG_NONE = 0,
    
    ENTITY_FLAG_MAPONLY = 0x00000004
};

class CEntity {
    public:
        static std::vector<CEntity*> EntityList;
    protected:
        CAnimation Anim_Control;
        SDL_Surface* Surf_Entity;
        SDL_Texture* Tex_Entity;
    public:
        float X;
        float Y;
        
        int Width;
        int Height;
        
        int AnimState;
        
        bool MoveLeft;
        bool MoveRight;
        bool MoveUp;
        bool MoveDown;
        bool SpaceDown;
        
        const char* string;
        bool print;
    public:
        int Type;
        
        bool Dead;
        int Flags;
    protected:
        float SpeedX;
        float SpeedY;
    protected:
        int CurrentFrameCol;
        int CurrentFrameRow;
    protected:
        int Col_X;
        int Col_Y;
        int Col_Width;
        int Col_Height;
    public:
        CEntity();
        virtual ~CEntity();
    public:
        virtual bool OnLoad(SDL_Renderer* Rend, char* File, int Width, int Height, int MaxFrames);
        virtual void OnLoop();
        virtual void OnRender(SDL_Renderer* Rend);
        virtual void OnCleanup();
        virtual void OnAnimate();
        virtual bool OnCollision(CEntity* Entity);
    public:
        void OnMove(float MoveX, float MoveY);
        void StopMove();
    public:
        bool Collides(int oX, int oY, int oW, int oH);
    private:
        bool PosValid(int NewX, int NewY);
        bool PosValidTile(CTile* Tile);
        bool PosValidEntity(CEntity* Entity, int NewX, int NewY);
    public:
        bool Print(CEntity* Entity);
        bool Text(SDL_Renderer* Rend, CEntity* Entity);
};

class CEntityCol {
    public:
        static std::vector<CEntityCol> EntityColList;
    public:
        CEntity* EntityA;
        CEntity* EntityB;
    public:
        CEntityCol();
};

#endif
