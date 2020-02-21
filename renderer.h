#ifndef RENDERER_H
#define RENDERER_H

#include "raylib.h"
#include <stdlib.h>
#include <stdio.h>
#include "tilegrid.h"
#include "entities.h"

#define NUM_SPRITES 1
#define NUM_ACTIONS 3

typedef struct AnimationData{
    int frames;
    int speed;
    Rectangle initial;
}AnimationData;

typedef struct SpriteData{
    AnimationData* animations;
}SpriteData;

SpriteData* initSpriteData(){
    SpriteData* data = (SpriteData*) malloc(sizeof(SpriteData)*NUM_SPRITES);
    for(int n = 0; n < NUM_SPRITES; n++){
        data[n].animations = (AnimationData*)malloc(sizeof(AnimationData)*NUM_ACTIONS);
    }
    data[0].animations[0].frames = 4;
    data[0].animations[0].speed = 1;
    Rectangle r1 = {16, 48, 48, 48};
    data[0].animations[0].initial = r1;
    data[0].animations[1].frames = 10;
    Rectangle r2 = {16, 0, 48, 48};
    data[0].animations[1].initial = r2;
    data[0].animations[1].speed = 2;
    
    return data;
}

int drawEntity(Texture2D sheet, SpriteData* data, Entity* entity){
    Rectangle tempRect = {data[entity->typeId].animations[entity->action].initial.x + (entity->animationFrame / (FRAMERATE / data[entity->typeId].animations[entity->action].frames)) * abs(data[entity->typeId].animations[entity->action].initial.width), 
        data[entity->typeId].animations[entity->action].initial.y, 
        data[entity->typeId].animations[entity->action].initial.width, 
        data[entity->typeId].animations[entity->action].initial.height};
    DrawTextureRec(sheet, tempRect, entity->position, WHITE);
    entity->animationFrame = (entity->animationFrame+data[entity->typeId].animations[entity->action].speed) % FRAMERATE;
    return 1;
}

int testRender(Texture2D tile){
    DrawTexture(tile, 0, 0, WHITE);
    return 1;
}

int testSamus(Texture2D sheet, Rectangle initial, Vector2 pos, int currentFrame){
    Rectangle tempRect = {initial.x + (currentFrame/12) * abs(initial.width), initial.y, initial.width, initial.height};
    DrawTextureRec(sheet, tempRect, pos, WHITE);
    return 1;
}



#endif