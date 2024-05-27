//
// Created by vanec on 5/26/2024.
//

#ifndef EXAMPLE_GAME_H
#define EXAMPLE_GAME_H


#include "Snake.h"
#include "Food.h"

class Game {
    unsigned int Score = 0;
public:
    Snake SnakeInstance;
    Food FoodInstance;

    Sound EatSound;
    Sound WallHitSound;


    void Draw();

    void CheckForFood();

    void Tick();

    void GameOver();

    void CheckCollisions();

    Game();
   ~Game();

    inline int GetScore() {
        return Score;
    }
};


#endif //EXAMPLE_GAME_H
