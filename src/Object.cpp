#include "Object.h"
#include "Player.h"

int Object::getX(){
    return this->X;
}
int Object::getY(){
    return this->Y;
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