//
// Created by vanec on 5/26/2024.
//

#include "Utils.h"

 Vector2 Utils::GetRandomVector2(int min, int max) {
    return Vector2{(float)GetRandomValue(min, max),(float)GetRandomValue(min, max)};
}


