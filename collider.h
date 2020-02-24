#ifndef COLLIDER_H
#define COLLIDER_H

#include "entities.h"
#include "tilegrid.h"
#include "utils.h"
#include "raylib.h"

int isEntityCollidingEntity(Entity e1, Entity e2){
    
}

int isEntityCollidingTile(Entity entity, Tile tile){
    int isColliding = 0;
    if((entity.position.x > getWorldPosFromTilePos(tile.position).x && entity.position.x < getWorldPosFromTilePos(tile.position).x + 16.0f)
        && (entity.position.y > getWorldPosFromTilePos(tile.position).y && entity.position.y < getWorldPosFromTilePos(tile.position).y + 16.0f))
    return isColliding;
}

#endif