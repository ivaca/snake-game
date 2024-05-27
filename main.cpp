#include <iostream>
#include "raylib.h"
#include "Core/Config.h"
#include "Core/Food.h"
#include "Core/Utils.h"
#include "Core/Snake.h"
#include "Core/Game.h"


int main() {



    InitWindow(2 * WINDOW_BORDER_OFFSET + CellSize * CellCount, 2 * WINDOW_BORDER_OFFSET + CellSize * CellCount,
               "Snake Game");
    SetTargetFPS(144);
    Game GameInstance;


    while (!WindowShouldClose()) {
        BeginDrawing();

        GameInstance.Tick();
        GameInstance.Draw();
        ClearBackground(Green);
        DrawRectangleLinesEx(Rectangle{float(WINDOW_BORDER_OFFSET-4),float(WINDOW_BORDER_OFFSET-4),CellSize*CellCount+8,CellSize*CellCount+8},4,DarkGreen);
        DrawText(TextFormat("Score: %i",GameInstance.GetScore()),WINDOW_WIDTH/2,26,22, WHITE);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}

