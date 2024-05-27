//
// Created by vanec on 5/26/2024.
//

#include <algorithm>
#include "Game.h"
#include "raymath.h"

void Game::Draw() {
    SnakeInstance.Draw();

    FoodInstance.Draw();
}

Game::Game() {
    SnakeInstance = Snake();
    FoodInstance = Food();

    InitAudioDevice();
    EatSound = LoadSound("F:\\Dev\\C++\\SnakeGame\\Sounds\\eat.mp3");
    WallHitSound = LoadSound("F:\\Dev\\C++\\SnakeGame\\Sounds\\wall.mp3");

}

void Game::Tick() {
    SnakeInstance.Tick();
    CheckForFood();
    CheckCollisions();
}

void Game::CheckForFood() {
    if (Vector2Equals(SnakeInstance.GetBody()[0], FoodInstance.GetPosition())) {
        FoodInstance = FoodInstance.GetRandomPosition();
        SnakeInstance.AteFood();
        PlaySound(EatSound);
        ++Score;
    }
}

void Game::CheckCollisions() {
    //If Snake leaves the grid
    if (SnakeInstance.GetBody()[0].x >= CellCount || SnakeInstance.GetBody()[0].x < 0) {

        GameOver();
    }
    if (SnakeInstance.GetBody()[0].y >= CellCount || SnakeInstance.GetBody()[0].y < 0) {

        GameOver();
    }
    //If Snake Hits own tail

    for (int i = 1; i < SnakeInstance.GetBody().size(); ++i) {
        if (Vector2Equals(SnakeInstance.GetBody()[i], SnakeInstance.GetBody()[0]))
            GameOver();
    }


}

void Game::GameOver() {
    PlaySound(WallHitSound);

    SnakeInstance = Snake();
    FoodInstance = Food();
    Score = 0;
}

Game::~Game() {
    //Unload all sounds
    UnloadSound(EatSound);
    UnloadSound(WallHitSound);
    CloseAudioDevice();
}

