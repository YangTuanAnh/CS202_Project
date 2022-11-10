#include "Global.h"

class Object{
private:
    int mX,mY;
    int direct;
    int counter;
public:
    //art
    Object(int,int,int,int);
    int getmX();
    int getmY();
    int getDirect();
    void move();
    void random();
};
vector<Object>obstacle;

class Car:public Object{
public:
    Car(int,int,int,int);
    int type();
};

class Truck:public Object{
public:
    Truck(int,int,int,int);
    int type();
};

class Bird:public Object{
public:
    Bird(int,int,int,int);
    int type();
};

class Dinausor:public Object{
public:
    Dinausor(int,int,int,int);
    int type();
};