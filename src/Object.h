#ifndef OBJECT_H
#define OBJECT_H

#include "Global.h"
#include "TextureHolder.h"

class Object{
protected:
    float X, Y;
    int direct;
	float velocity;
	int t;
	TextureHolder* mTextures;
public:
    //get info
    float getX();
    float getY();
    virtual int getDirect(){return -1;};

    //set up obstacle
    virtual void move();
	virtual int type() { return 0; };
	int dir() { return this->direct; }
	Object(float x, float y, int d, float velocity, TextureHolder* mTextures) { this->X = x; this->Y = y; this->direct = d; this->velocity = velocity; this->t = 0; this->mTextures = mTextures; }
	Object(float x,float y,int d){this->x = x;this->y = y;this->direct = d;}
	virtual void draw();
	virtual ~Object();
};

class Car:public Object{
public:
    void move() { this->X += this->velocity * (float)this->direct; };
	Car(int x, int y, int d, float velocity, TextureHolder* mTextures) :Object(x, y, d, velocity, mTextures) {};
	Car(float x,float y,int d){this->X = x;this->Y = y;this->direct = d;}
	int type() { this->t = 2; return 2; }
	int getDirect() { return this->direct; }
	void draw();
	~Car();
};

class Truck:public Object{
public:
    void move(){ this->X += this->velocity * (float)this->direct; };
	Truck(int x, int y, int d, float velocity, TextureHolder* mTextures) :Object(x, y, d, velocity, mTextures) {};
	Truck(float x,float y,int d){this->X = x;this->Y = y;this->direct = d;}
	int type() { this->t = 3; return 3; }
	int getDirect() { return this->direct; }
	void draw();
	~Truck();
};

class Bird:public Object{
public:
   	void move(){ this->X += this->velocity * (float)this->direct; };
	Bird(int x, int y, int d, float velocity, TextureHolder* mTextures) :Object(x, y, d, velocity, mTextures) {};
	Bird(float x,float y,int d){this->X = x;this->Y = y;this->direct = d;}
	int type() { this->t = 4; return 4; }
	int getDirect() { return this->direct; }
	void draw();
	~Bird();
};

class Dinausor:public Object{
public:
    void move(){ this->X += this->velocity * (float)this->direct; };
	Dinausor(int x, int y, int d, float velocity, TextureHolder* mTextures) :Object(x, y, d, velocity, mTextures) {};
	Dinausor(float x,float y,int d){this->X = x;this->Y = y;this->direct = d;}
	int type() { this->t = 5; return 5; }
	int getDirect() { return this->direct; }
	void draw();
	~Dinausor();
};
class Obstacle:public Object{
public:
	void move() { this->X += 0; this->Y += 0; };
	Obstacle(int x, int y, int d, float velocity, TextureHolder* mTextures) :Object(x, y, d, velocity, mTextures) {};
	Obstacle(float x,float y,int d){this->X = x;this->Y = y;this->direct = d;}
	int type() { this->t = 1;return 1; }
	int getDirect() { return this->direct; }
	void draw();
	~Obstacle();
};
#endif