//global defines:

#define FRAMERATE 120
#define GRID_SIZE 65536

#include "raylib.h"
#include "tilegrid.h"
#include "renderer.h"
#include "init.h"
#include "entities.h"

#define PAL_SPACEBLUE CLITERAL{ 0, 0, 10, 255 }

int main(void)
{
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 1600;
    const int screenHeight = 900;
    int currentFrame = 0;
    Rectangle samusInitial = {16, 96, 48, 48};
    Vector2 samusPos = {200.0, 200.0};
    Vector2 playerPos = {100.0, 200.0};
    Entity player = {0, 0, 0, 1, 0, playerPos};
    
    SpriteData* SPRITE_DATA = initSpriteData();

    InitWindow(screenWidth, screenHeight, "alien ripoff sim 2020");
    Texture2D sheet = LoadTexture("resources/tiles/test_tile.png");
    
    Camera2D cam = {0};
    cam.zoom = 4.0f;
    Vector2 offset = {100.0, -100.0};
    cam.offset = offset;

    SetTargetFPS(FRAMERATE);         
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Draw
        //----------------------------------------------------------------------------------
        if(IsKeyDown(KEY_A)){
            cam.offset.x -= 1.0f;
        }
        if(IsKeyDown(KEY_D)){
            cam.offset.x += 1.0f;
        }
        if(IsKeyDown(KEY_W)){
            cam.offset.y -= 1.0f;
        }
        if(IsKeyDown(KEY_S)){
            cam.offset.y += 1.0f;
        }
        
        BeginDrawing();
        BeginMode2D(cam);

        ClearBackground(PAL_SPACEBLUE);
        testRender(sheet);
        testSamus(sheet, samusInitial, samusPos, currentFrame++);
        drawEntity(sheet, SPRITE_DATA, &player);
        currentFrame = currentFrame % FRAMERATE;
            
            
        EndMode2D();
        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------
    UnloadTexture(sheet);
    return 0;
}