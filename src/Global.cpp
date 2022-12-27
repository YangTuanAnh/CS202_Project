#include "Global.h"

Vector2 convertCar2IsoVector(Vector2 Cartesian) {
    Vector2 isometricVector;
    isometricVector.x = Cartesian.x - Cartesian.y + SCREEN_WIDTH/2;
    // if (Cartesian.x > 0)
    //     Cartesian.y += Cartesian.x/2;
    // else if (Cartesian.x == 0)
    //     Cartesian.y /= 2;
    isometricVector.y = (Cartesian.x + Cartesian.y)/2;
    return isometricVector;
}