#include "CMap.h"

CMap CMap::MapControl;

CMap::CMap() {
    Surf_Tileset = NULL;
    Tex_Tileset = NULL;
    MapSize = 0;
}

bool CMap::OnLoad(SDL_Renderer* Rend, char* MapFile, char* TileFile) {
    TileList.clear();
    
    if((Surf_Tileset = CTexture::OnLoad(TileFile)) == false)
    {
        return false;
    }
    
    Tex_Tileset = CTexture::S2T(Rend, Surf_Tileset);
    
    FILE* FileHandle = fopen(MapFile, "r");
    if (FileHandle == NULL)
    {
        return false;
    }
    
    for (int Y = 0; Y < MAP_HEIGHT; Y++)
    {
        for (int X = 0; X < MAP_WIDTH; X++)
        {
            CTile tempTile;
            fscanf(FileHandle, "%d:%d ", &tempTile.TileID, &tempTile.TypeID);
            TileList.push_back(tempTile);
        }
        fscanf(FileHandle, "\n");
    }
    fclose(FileHandle);
    
    return true;
}

void CMap::OnRender(SDL_Renderer* Rend, SDL_Surface* Surface, int MapX, int MapY) {
    if (Surf_Tileset == NULL || Rend == NULL) return;
    
    // TilesetWidth/Height are in number of tiles, not number of pixels
    int TilesetWidth = Surf_Tileset->w / TILE_SIZE;
    int TilesetHeight = Surf_Tileset->h / TILE_SIZE;
    
    int ID = 0;
    
    //Loop also goes through number of tiles, not number of pixels
    for (int Y = 0; Y < MAP_HEIGHT; Y++)
    {
        for (int X = 0; X < MAP_WIDTH; X++)
        {
            if (TileList[ID].TypeID == TILE_TYPE_NONE)
            {
                ID++;
                continue;
            }
            
            // need to convert back to pixels to figure out where to draw on screen
            int tX = MapX + (X * TILE_SIZE);
            int tY = MapY + (Y * TILE_SIZE);
            
            // Calculate where on the Tileset to grab the appropriate tile
            int TilesetX = (TileList[ID].TileID % TilesetWidth) * TILE_SIZE;
            int TilesetY = (TileList[ID].TileID / TilesetWidth) * TILE_SIZE;
            
            Tex_Tileset = CTexture::S2T(Rend, Surf_Tileset);
            CTexture::OnDraw(Rend, Tex_Tileset, tX, tY, TilesetX, TilesetY, TILE_SIZE, TILE_SIZE);
            
            ID++;
        }
    }
}

void CMap::OnRender(SDL_Renderer* Rend, SDL_Texture* Texture, int MapX, int MapY) {
    if (Tex_Tileset == NULL || Rend == NULL) return;
    
    // TilesetWidth/Height are in number of tiles, not number of pixels
    
    int w;
    int h;
    SDL_QueryTexture(Tex_Tileset, NULL, NULL, &w, &h);
    int TilesetWidth = w / TILE_SIZE;
    int TilesetHeight = h / TILE_SIZE;
    
    int ID = 0;
    
    //Loop also goes through number of tiles, not number of pixels
    for (int Y = 0; Y < MAP_HEIGHT; Y++)
    {
        for (int X = 0; X < MAP_WIDTH; X++)
        {
            if (TileList[ID].TypeID == TILE_TYPE_NONE)
            {
                ID++;
                continue;
            }
            
            // need to convert back to pixels to figure out where to draw on screen
            int tX = MapX + (X * TILE_SIZE);
            int tY = MapY + (Y * TILE_SIZE);
            
            // Calculate where on the Tileset to grab the appropriate tile
            int TilesetX = (TileList[ID].TileID % TilesetWidth) * TILE_SIZE;
            int TilesetY = (TileList[ID].TileID / TilesetWidth) * TILE_SIZE;
            
            CTexture::OnDraw(Rend, Tex_Tileset, tX, tY, TilesetX, TilesetY, TILE_SIZE, TILE_SIZE);
            
            ID++;
        }
    }
}

CTile* CMap::GetTile (int X, int Y) {
    int ID = 0;
    
    ID = X / TILE_SIZE;
    ID = ID + (MAP_WIDTH * (Y / TILE_SIZE));
    
    if (ID < 0 || ID >= TileList.size())
    {
        return NULL;
    }
    
    return &TileList[ID];
}

void CMap::OnCleanup() {
    if (Surf_Tileset)
    {
        SDL_FreeSurface(Surf_Tileset);
    }
    if (Tex_Tileset)
    {
        SDL_DestroyTexture(Tex_Tileset);
    }
    TileList.clear();
}
