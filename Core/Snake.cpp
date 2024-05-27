//
// Created by vanec on 5/26/2024.
//

#include "Snake.h"
#include "raymath.h"

void Snake::Draw() {
    for (int i = 0; i < Body.size(); ++i) {
        DrawRectangleRounded(Rectangle{WINDOW_BORDER_OFFSET+Body[i].x * CellSize, WINDOW_BORDER_OFFSET+Body[i].y * CellSize, CellSize, CellSize}, 0.48f, 6,
                             DarkGreen);
    }
}

void Snake::Tick() {

    Move();

    CheckUserInput();
}

void Snake::Move() {
    if (Wait(Speed)) {
        Body.pop_back();
        Body.push_front(Vector2Add(Body[0], MoveDirectionVector));
    }

}

void Snake::ChangeDirection(MoveDirection Dir) {
    switch (Dir) {
        case MoveDirection::UP:
            MoveDirectionVector = Vector2{0, -1};
            break;
        case MoveDirection::DOWN:
            MoveDirectionVector = Vector2{0, 1};
            break;
        case MoveDirection::LEFT:
            MoveDirectionVector = Vector2{-1, 0};
            break;

        case MoveDirection::RIGHT:
            MoveDirectionVector = Vector2{1, 0};
            break;
    }

}

void Snake::CheckUserInput() {
    if (IsKeyPressed(KEY_W) && MoveDirectionVector.y!=1) {

        ChangeDirection(MoveDirection::UP);
    }
    if (IsKeyPressed(KEY_S) && MoveDirectionVector.y!=-1) {
        ChangeDirection(MoveDirection::DOWN);
    }
    if (IsKeyPressed(KEY_A)&& MoveDirectionVector.x!=1) {
        ChangeDirection(MoveDirection::LEFT);
    }
    if (IsKeyPressed(KEY_D)&& MoveDirectionVector.x!=-1) {
        ChangeDirection(MoveDirection::RIGHT);
    }

}

bool Snake::Wait(double Delta) {

    double CurrentDeltaTime = GetTime();
    if (CurrentDeltaTime - GameDeltaTime >= Delta) {
        GameDeltaTime = CurrentDeltaTime;
        return true;
    }
    return false;

}

void Snake::AteFood() {
    Body.push_back(Vector2Add(Body[Body.size()-1],MoveDirectionVector));
}
