#include "Global.h"
class Object{
protected:
    int mX,mY;
    int direct;
    int size;
public:
    //art
    Object(int,int,int,int);//constructor
    //get info
    int getmX();
    int getmY();
    int getsize();
    int getDirect();

    //set up obstacle
    void setmX(int);
    void setmY(int);
    void setsize(int);
    void setDirect(int);

    void move(Player*p);//virtual
    virtual int type(){return -1;};//get the type
    virtual ~Object();//des
};
vector<Object>obstacle;

class Car:public Object{
public:
    Car(int,int,int,int);
    int type();
    ~Car();
};

class Truck:public Object{
public:
    Truck(int,int,int,int);
    int type();
    ~Truck();
};

class Bird:public Object{
public:
    Bird(int,int,int,int);
    int type();
    ~Bird();
};

class Dinausor:public Object{
public:
    Dinausor(int,int,int,int);
    int type();
    ~Dinausor();
};