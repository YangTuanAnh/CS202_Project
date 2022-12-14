#ifndef OBJECT_H
#define OBJECT_H
#include "Global.h"
#include "TextureHolder.h"
class Object{
protected:
    int X,Y;
    int direct;
	int t;
	TextureHolder* mTextures;
public:
    //get info
    int getX();
    int getY();
    virtual int getDirect(){return -1;};

    //set up obstacle
    virtual void move();
	virtual int type() { return 0; };
	int dir() { return this->direct; }
	Object(int x, int y, int d, TextureHolder* mTextures) { this->X = x; this->Y = y; this->direct = d; this->t = 0; this->mTextures = mTextures; }
	virtual void draw();
	virtual ~Object();
};

class Car:public Object{
public:
    void move() { this->X += 1 * direct;};
	Car(int x, int y, int d, TextureHolder* mTextures) :Object(x, y, d, mTextures) {};
	int type() { this->t = 2; return 2; }
	int getDirect() { return this->direct; }
	void draw();
	~Car();
};

class Truck:public Object{
public:
    void move(){ this->X += 1 * direct; };
	Truck(int x, int y, int d, TextureHolder* mTextures) :Object(x, y, d, mTextures) {};
	int type() { this->t = 3; return 3; }
	int getDirect() { return this->direct; }
	void draw();
	~Truck();
};

class Bird:public Object{
public:
   	void move(){ this->X += 1 * direct; };
	Bird(int x, int y, int d, TextureHolder* mTextures) :Object(x, y, d, mTextures) {};
	int type() { this->t = 4; return 4; }
	int getDirect() { return this->direct; }
	void draw();
	~Bird();
};

class Dinausor:public Object{
public:
    void move(){ this->X += 1 * direct; };
	Dinausor(int x, int y, int d, TextureHolder* mTextures) :Object(x, y, d, mTextures) {};
	int type() { this->t = 5; return 5; }
	int getDirect() { return this->direct; }
	void draw();
	~Dinausor();
};
class Obstacle:public Object{
public:
	void move() { this->X += 0; this->Y += 0; };
	Obstacle(int x, int y, int d, TextureHolder* mTextures) :Object(x, y, d, mTextures) {};
	int type() { this->t = 1;return 1; }
	int getDirect() { return this->direct; }
	void draw();
	~Obstacle();
};
#endif