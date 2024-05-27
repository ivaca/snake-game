#ifndef CONFIG_H
#define CONFIG_H

#include "raylib.h"


const int WINDOW_WIDTH = 600;
const int WINDOW_HEIGHT = 600;
const int WINDOW_BORDER_OFFSET = 60;
//Colors
const Color Green = {172, 204, 96, 255};
const Color DarkGreen = {42, 52, 24, 255};
//Game Config
const int CellSize = 30;
const int CellCount = WINDOW_WIDTH / CellSize;
#endif