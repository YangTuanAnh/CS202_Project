#include "Vehicle.h"

Object::Object(int mX,int mY,int direct,int counter){
    this->mX = mX;
    this->mY = mY;
    this->direct = direct;
    this->counter= counter;
}
int Object::getmX(){
    return this->mX;
}
int Object::getmY(){
    return this->mY;
}
int Object::getDirect(){
    return this->direct;
}
void Object::move(){
    int r = rand()%2;
    if(r ==1)
        this->mX+=1*this->counter;
    else
        this->mX-=1*this->counter;
}

Car::Car(int mX,int mY,int direct,int counter):Object(mX,mY,direct,counter){

}
Truck::Truck(int mX,int mY,int direct,int counter):Object(mX,mY,direct,counter){

}
Bird::Bird(int mX,int mY,int direct,int counter):Object(mX,mY,direct,counter){

}
Dinausor::Dinausor(int mX,int mY,int direct,int counter):Object(mX,mY,direct,counter){

}

int Car::type(){
    return 0;
}
int Truck::type(){
    return 1;
}
int Bird::type(){
    return 2;
}
int Dinausor::type(){
    return 3;
}

void Object::random(){
    
}