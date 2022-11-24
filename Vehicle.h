#include "Global.h"
class Object{
protected:
    int mX,mY;
    int direct;
    int counter;
    int size;
public:
    //art
    Object(int,int,int,int);
    int getmX();
    int getmY();
    int getsize();
    int getDirect();
    void setmX(int);
    void setmY(int);
    void setsize(int);
    void setDirect(int);
    void move(Player*p);
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