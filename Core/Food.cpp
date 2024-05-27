#include "Food.h"
#include "Config.h"
#include "Utils.h"


Food::Food() : Food(GetRandomPosition()) {

}

Food::Food(Vector2 Position) {
    this->Position = Position;


    //Load Food Image From Disk
    Image FoodImage = LoadImage("F:\\Dev\\C++\\SnakeGame\\Graphics\\food.png");
    Texture = LoadTextureFromImage(FoodImage);
    UnloadImage(FoodImage);
}

void Food::Draw() {
    DrawTexture(Texture, WINDOW_BORDER_OFFSET+Position.x * CellSize, WINDOW_BORDER_OFFSET+Position.y * CellSize, WHITE);
}


Food::~Food() {
    UnloadTexture(Texture);
}

