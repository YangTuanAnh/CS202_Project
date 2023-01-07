#pragma once

#include <iostream>
#include <conio.h>
#include <random>
#include <vector>
#include <fstream>
#include <raygui.h>
using namespace std;

// Global variables
const int SCREEN_WIDTH = 1200;
const int SCREEN_HEIGHT = 580;
const int FPS = 60;
const float CAR_SPEED = 180.0f;
const float TRUCK_SPEED = 120.0f;
const float DINOSAUR_SPEED = 90.0f;
const float BIRD_SPEED = 210.0f;
const int OBJECT_COUNT = 5;
const int MAX_SPAWN_TIME = 5;
const int LAMP_TIME = 3;

const float BLOCK_SIZE = 40.0f;
const int MAP_WIDTH = 15;
const int LANE_COUNT = 5;

// Global functions
Vector2 convertCar2IsoVector(Vector2 Cartesian);

// Vector2 convertCar2IsoVector(float mX, float mY) {
//     Vector2 isometricVector;
//     isometricVector.x = mX - mY + SCREEN_WIDTH/2;
//     // if (Cartesian.x > 0)
//     //     Cartesian.y += Cartesian.x/2;
//     // else if (Cartesian.x == 0)
//     //     Cartesian.y /= 2;
//     isometricVector.y = (mX + mY)/2;
//     return isometricVector;
// }