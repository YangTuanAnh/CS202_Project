#include "Global.h"
class Object{
protected:
    int X,Y;
    int direct;
	int t;
public:
    //get info
    int getX();
    int getY();
    virtual int getDirect(){return -1;};

    //set up obstacle
    virtual void move();
	virtual int type() { return 0; };
	int dir() { return this->direct; }
	Object(int x, int y, int d) { this->X = x; this->Y = y; this->direct = d; this->t = 0; }
	void display();
	virtual ~Object();
};
vector<Object>obstacle;

class Car:public Object{
public:
    void move() { this->X += 1 * direct;};
	Car(int x, int y,int d) :Object(x, y,d) {};
	int type() { this->t = 2; return 2; }
	int getDirect() { return this->direct; }
	~Car();
};

class Truck:public Object{
public:
    void move(){ this->X += 1 * direct; };
	Truck(int x, int y,int d) :Object(x, y,d) {};
	int type() { this->t = 3; return 3; }
	int getDirect() { return this->direct; }
	~Truck();
};

class Bird:public Object{
public:
   	void move(){ this->X += 1 * direct; };
	Bird(int x, int y,int d) :Object(x, y,d) {};
	int type() { this->t = 4; return 4; }
	int getDirect() { return this->direct; }
	~Bird();
};

class Dinausor:public Object{
public:
    void move(){ this->X += 1 * direct; };
	Dinausor(int x, int y,int d) :Object(x, y,d) {};
	int type() { this->t = 5; return 5; }
	int getDirect() { return this->direct; }
	~Dinausor();
};
class Obstacle:public Object{
public:
	void move() { this->X += 0; this->Y += 0; };
	Obstacle(int x, int y,int d) :Object(x, y,d) {};
	int type() { this->t = 1;return 1; }
	int getDirect() { return this->direct; }
	~Obstacle();
};