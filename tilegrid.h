#ifndef TILEGRID_H
#define TILEGRID_H

#include <raylib.h>
#include "utils.h"

typedef struct Tile{
    IntVector2 position;
    int type;
}Tile;

typedef struct TileGrid{
    IntVector2 size;
    Tile* tiles;
}TileGrid;

typedef struct Map{
    TileGrid* grid;
    
}Map;

Tile* getTileAt(TileGrid* grid, IntVector2 pos){
    return &grid->tiles[pos.x + pos.y * GRID_SIZE];
}

TileGrid* initTileGrid(IntVector2 size){
    TileGrid* grid = (TileGrid*) malloc(sizeof(TileGrid));
    grid->size = size;
    grid->tiles = (Tile*) malloc(sizeof(Tile) * size.x * size.y);
    return grid;
}

#endif