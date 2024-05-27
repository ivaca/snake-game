//
// Created by vanec on 5/26/2024.
//

#ifndef EXAMPLE_SNAKE_H
#define EXAMPLE_SNAKE_H

#include <deque>
#include "raylib.h"
#include "Config.h"

enum class MoveDirection {
    UP, DOWN, LEFT, RIGHT
};


class Snake {
    std::deque<Vector2> Body = {Vector2{5, 9}, Vector2{5, 8}, Vector2{5, 7}};
    Vector2 MoveDirectionVector{0, 1};
public:
    void Draw();

    void Tick();

    void Move();
    void AteFood();
    void ChangeDirection(MoveDirection Dir);

    inline const std::deque<Vector2>& GetBody() { return Body; }

private:
    float Speed = 0.2f;

    void CheckUserInput();

    bool Wait(double Delta);

    double GameDeltaTime = 0.0;

};


#endif //EXAMPLE_SNAKE_H
