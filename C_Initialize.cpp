#include "CGame.h"

bool CGame::OnInit()
{
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
    {
        return false;
    }
     //Initialize SDL_ttf 
     if( TTF_Init() == -1 ) 
     { 
        printf( "SDL_ttf could not initialize! SDL_ttf Error: %s\n", TTF_GetError() );
        return false; 
     }
    
    if ((Window = SDL_CreateWindow("VideoGame",
                                        SDL_WINDOWPOS_UNDEFINED,
                                        SDL_WINDOWPOS_UNDEFINED,
                                        WWIDTH, WHEIGHT,
                                        SDL_WINDOW_RESIZABLE)) == NULL)
    {
        return false;
    }
    if ((Rend = SDL_CreateRenderer(Window,
                                    -1,
                                    SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC))
                                    == NULL)
    {
        return false;
    }
//    if ((TextRend = SDL_CreateRenderer(Window,
//                                    -1,
//                                    SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC))
//                                    == NULL)
//                                    
//    {
//        return false;
//    }
    // Initialize the Map and Tiles
    if (CMap::MapControl.OnLoad(Rend, "./maps/2.map.txt", "./tilesets/maintileset.png") == false)
    {
        return false;
    }
    
    // Initialize Entities
    
    // Yoshi
    if (Test.OnLoad(Rend, "./sprites/yoshi.png", 64, 64, 8) == false)
    {
        return false;
    }
    Test.X = 600;
    Test.Y = 400;
    Test.string = "Welcome to Ma-land! (Pronounced May-land).";
    CEntity::EntityList.push_back(&Test);
    
    // Malan
    if (Malan.OnLoad(Rend, "./sprites/malan.png", 225, 225, 1) == false)
    {
        return false;
    }
    Malan.X = 1600;
    Malan.Y = 1600;
    CEntity::EntityList.push_back(&Malan);
    
    // Trees
    if (Tree.OnLoad(Rend, "./sprites/tree.png", 132, 174, 1) == false)
    {
        return false;
    }
    Tree.X = 1000;
    Tree.Y = 500;
    Tree.string = "......";
    CEntity::EntityList.push_back(&Tree);
    
    if (Tree2.OnLoad(Rend, "./sprites/tree.png", 132, 174, 1) == false)
    {
        return false;
    }
    Tree2.X = 500;
    Tree2.Y = 1200;
    Tree2.string = "Trees do not speak.";
    CEntity::EntityList.push_back(&Tree2);
    
    if (Tree3.OnLoad(Rend, "./sprites/tree.png", 132, 174, 1) == false)
    {
        return false;
    }
    Tree3.X = 1500;
    Tree3.Y = 1500;
    Tree3.string = "You're barking up the wrong...nevermind.";
    CEntity::EntityList.push_back(&Tree3);
    
    if (Tree4.OnLoad(Rend, "./sprites/tree.png", 132, 174, 1) == false)
    {
        return false;
    }
    Tree4.X = 1800;
    Tree4.Y = 1500;
    Tree4.string = "Birch, please.";
    CEntity::EntityList.push_back(&Tree4);
    
    //Houses
    if (House1.OnLoad(Rend, "./sprites/2.house.png", 168, 166, 1) == false)
    {
        return false;
    }
    House1.X = 2500;
    House1.Y = 500;
    CEntity::EntityList.push_back(&House1);
    
    if (House2.OnLoad(Rend, "./sprites/2.house.png", 168, 166, 1) == false)
    {
        return false;
    }
    House2.X = 2300;
    House2.Y = 500;
    CEntity::EntityList.push_back(&House2);
    
    if (House3.OnLoad(Rend, "./sprites/1.house.png", 176, 144, 1) == false)
    {
        return false;
    }
    House3.X = 2500;
    House3.Y = 750;
    CEntity::EntityList.push_back(&House3);
    
    if (House4.OnLoad(Rend, "./sprites/1.house.png", 176, 144, 1) == false)
    {
        return false;
    }
    House4.X = 2300;
    House4.Y = 750;
    CEntity::EntityList.push_back(&House4);
    
    // Townspeople
    if (Cat1.OnLoad(Rend, "./sprites/scratchcat2.png", 120, 128, 2) == false)
    {
        return false;
    }
    Cat1.X = 1500;
    Cat1.Y = 1750;
    Cat1.string = "ALL HAIL THE GREAT CREATOR!!!!!!!1!!11";
    CEntity::EntityList.push_back(&Cat1);
    
    if (Cat2.OnLoad(Rend, "./sprites/scratchcat2.png", 120, 128, 2) == false)
    {
        return false;
    }
    Cat2.X = 1800;
    Cat2.Y = 1750;
    Cat2.string = "NONE MAY STEP ON THE FACE OF THE GREAT CREATOR! GET AWAY >:(";
    CEntity::EntityList.push_back(&Cat2);
    
    if (Yoshi2.OnLoad(Rend, "./sprites/yoshi.png", 64, 64, 1) == false)
    {
        return false;
    }
    Yoshi2.X = 800;
    Yoshi2.Y = 2300;
    Yoshi2.string = "This is smile flower corner. Isn't life amazing?";
    CEntity::EntityList.push_back(&Yoshi2);
    
    if (Yoshi3.OnLoad(Rend, "./sprites/yoshi.png", 64, 64, 8) == false)
    {
        return false;
    }
    Yoshi3.X = 2800;
    Yoshi3.Y = 2200;
    Yoshi3.string = "Hello, world. I wonder what's beyond Ma-land.";
    CEntity::EntityList.push_back(&Yoshi3);
    
    if (Yoshi4.OnLoad(Rend, "./sprites/yoshi.png", 64, 64, 8) == false)
    {
        return false;
    }
    Yoshi4.X = 2200;
    Yoshi4.Y = 800;
    Yoshi4.string = "These homes were not built with working doors. Time constraints, you know.";
    CEntity::EntityList.push_back(&Yoshi4);
    
    // Initialize the Player and handle Camera stuff
    if (Player.OnLoad(Rend, "./sprites/p2.png", 38, 52, 4) == false)
    {
        return false;
    }
    CEntity::EntityList.push_back(&Player);
    
    Player.X = 640;
    Player.Y = 480;
    
    CCamera::CameraControl.TargetMode = TARGET_MODE_CENTER;
    CCamera::CameraControl.SetTarget(&Player.X, &Player.Y);
    
    // Text
    
    // Loading - End
    return true;
}
