#include "Vehicle.h"
#include "People.h"

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
int Object::getsize(){
    return this->size;
}
int Object::getDirect(){
    return this->direct;
}
void Object::move(Player*p){
    int r = rand()%2;
    if(r ==1)
        this->mX+=1*this->counter;
    else
        this->mX-=1*this->counter;
}

Car::Car(int mX,int mY,int direct,int counter):Object(mX,mY,direct,counter){
    this->size =1;
}
Truck::Truck(int mX,int mY,int direct,int counter):Object(mX,mY,direct,counter){
    this->size = 2;
}
Bird::Bird(int mX,int mY,int direct,int counter):Object(mX,mY,direct,counter){
    this->size = 1;
}
Dinausor::Dinausor(int mX,int mY,int direct,int counter):Object(mX,mY,direct,counter){
    this->size = 2;
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

void Object::setmX(int x){
    this->mX = x;
}
void Object::setmY(int y){
    this->mY = y;
}
void Object::setsize(int s){
    this->size = s;
}
void Object::setDirect(int d){
    this->direct = d;
}
Dinausor::~Dinausor(){
    this->counter = 0 ;
    this->direct = 0;
    this->mX = 0;
    this->mY = 0;
    this->size = 0;
}
Car::~Car(){
    this->counter = 0 ;
    this->direct = 0;
    this->mX = 0;
    this->mY = 0;
    this->size = 0;
}
Truck::~Truck(){
    this->counter = 0 ;
    this->direct = 0;
    this->mX = 0;
    this->mY = 0;
    this->size = 0;
}
Bird::~Bird(){
    this->counter = 0 ;
    this->direct = 0;
    this->mX = 0;
    this->mY = 0;
    this->size = 0;
}
Object::~Object(){
    this->counter= 0;
    this->direct=0;
    this->size=0;
}