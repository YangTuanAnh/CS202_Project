#include "Global.h"

class Object{
protected:
	int X, Y, direct,t;
public:
	virtual void move();
	virtual int type() { return 0; };
	int dir() { return this->direct; }
	Object(int x, int y, int d) { this->X = x; this->Y = y; this->direct = d; this->t = 0; }
	void display();
	int getX();
	int getY();
    int getDirect();
    virtual ~Object();
};
class Obstacle :public Object {
public:
	void move() { this->X += 0; this->Y += 0; };
	Obstacle(int x, int y,int d) :Object(x, y,d) {};
	int type() { this->t = 1;return 1; }
	int dir() { return this->direct; }
    ~Obstacle();
};
class Car :public Object {
public:
	void move() { this->X += 1 * direct;};
	Car(int x, int y,int d) :Object(x, y,d) {};
	int type() { this->t = 2; return 2; }
    ~Car();
};
class Truck :public Object {
public:
	void move(){ this->X += 1 * direct; };
	Truck(int x, int y,int d) :Object(x, y,d) {};
	int type() { this->t = 3; return 3; }
    ~Truck();
};
class Bird :public Object {
public:
	void move(){ this->X += 1 * direct; };
	Bird(int x, int y,int d) :Object(x, y,d) {};
	int type() { this->t = 4; return 4; }
    ~Bird();
};
class Dinausor :public Object {
public:
	void move(){ this->X += 1 * direct; };
	Dinausor(int x, int y,int d) :Object(x, y,d) {};
	int type() { this->t = 5; return 5; }
    ~Dinausor();
};

