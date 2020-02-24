#ifndef ENTITIES_H
#define ENTITIES_H

#include "utils.h"

typedef enum Behavior{
    NONE = 0, ATTACK, HIDE
}Behavior;

typedef enum Action{
    IDLE = 0, RUN, JUMP, AIM_FWD, AIM_UP
}Action;

typedef struct Entity{
    int typeId;
    int direction; //-1 is left, 1 is right
    int animationFrame;
    int interFrame; //frames per frame, i guess. counts from 0 to n, then increments animation frame at n
    Vector2 size;
    Action action; 
    Behavior behavior;
    Vector2 position;
}Entity;

#endif