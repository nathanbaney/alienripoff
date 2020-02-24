#ifndef UTILS_H
#define UTILS_H

#include "raylib.h"

typedef struct IntVector2{
    int x;
    int y;
}IntVector2;

IntVector2 getTilePosFromWorldPos(Vector2 worldPos){
    IntVector2 tilePos = {(int)worldPos.x / 16.0, (int)worldPos.y / 16.0};
    return tilePos;
}
Vector2 getWorldPosFromTilePos(IntVector2 tilePos){
    Vector2 worldPos = {tilePos.x * 16.0, tilePos.y * 16.0};
    return worldPos;
}

#endif