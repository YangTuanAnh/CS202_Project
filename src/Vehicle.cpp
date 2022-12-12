#include "Vehicle.h"
#include "Player.h"

int Object::getX(){
    return this->X;
}
int Object::getY(){
    return this->Y;
}
int Object::getDirect(){
    return this->direct;
}

void Object::setmX(int x){
    this->X = x;
}
void Object::setmY(int y){
    this->Y = y;
}
Dinausor::~Dinausor(){
    this->direct = 0;
    this->X = 0;
    this->Y = 0;
}
Car::~Car(){
    this->direct = 0;
    this->X = 0;
    this->Y = 0;
}
Truck::~Truck(){
    this->direct = 0;
    this->X = 0;
    this->Y = 0;
}
Bird::~Bird(){
    this->direct = 0;
    this->X = 0;
    this->Y = 0;

}
Object::~Object(){
    this->direct = 0;
    this->X = 0;
    this->Y = 0;
}
Obstacle::~Obstacle(){
    this->direct = 0;
    this->X = 0;
    this->Y = 0;
}