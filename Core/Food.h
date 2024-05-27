#ifndef EXAMPLE_FOOD_H
#define EXAMPLE_FOOD_H

#include "raylib.h"
#include "Config.h"
#include "Utils.h"

class Food {
    Vector2 Position;
    Texture2D Texture;
public:
    Food(Vector2 Position);

    Food();
    void Draw();

    inline const Vector2 &GetPosition() { return Position; }
    inline Vector2  GetRandomPosition(){return Utils::GetRandomVector2(0,CellCount - 1);}
    ~Food();
};


#endif //EXAMPLE_FOOD_H
