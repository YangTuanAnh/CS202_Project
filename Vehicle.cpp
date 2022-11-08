#include "Vehicle.h"

void CVEHICLE::Move(int x,int y){
    int speed;
    int res = rand() % 2;
    if(res ==1){
        //move left
        y = leftpointofscreen;
        y = y +1*speed;
    }
    else{
        //move right
        y = rightpointofscreen;
        y = y-1*speed;
    }
}