#ifndef OBJECT_H
#define OBJECT_H

#include "Global.h"
#include "TextureHolder.h"

// Object velocity define
#define V_OBSTACLE 0.0f

// normal mode
#define V_CAR_N 2.0f
#define V_TRUCK_N 2.5f
#define V_BIRD_N 3.5f
#define V_DINAUSOR_N 1.5f

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
	Object(float x, float y, int d) { this->X = x; this->Y = y; this->direct = d; };
	Object(float x, float y, int d, float velocity, TextureHolder* mTextures) { this->X = x; this->Y = y; this->direct = d; this->velocity = velocity; this->t = 0; this->mTextures = mTextures; }
	virtual void draw();
	virtual ~Object();
};

class Car:public Object{
public:
    void move() {
		if (this->X == 1200)
			this->X = 0.0f;
		else
			this->X += this->velocity * (float)this->direct;
	};
	Car(int x, int y, int d) : Object(x, y, d) {};
	Car(int x, int y, int d, float velocity, TextureHolder* mTextures) :Object(x, y, d, velocity, mTextures) {};
	int type() { this->t = 2; return 2; }
	int getDirect() { return this->direct; }
	void draw();
	~Car();
};

class Truck:public Object{
public:
    void move() {
		if (this->X == 1200)
			this->X = 0.0f;
		else
			this->X += this->velocity * (float)this->direct;
	};
	Truck(int x, int y, int d) : Object(x, y, d) {};
	Truck(int x, int y, int d, float velocity, TextureHolder* mTextures) :Object(x, y, d, velocity, mTextures) {};
	int type() { this->t = 3; return 3; }
	int getDirect() { return this->direct; }
	void draw();
	~Truck();
};

class Bird:public Object{
public:
	void move() {
		if (this->X == 1200)
			this->X = 0.0f;
		else
			this->X += this->velocity * (float)this->direct;
	};
	Bird(int x, int y, int d) : Object(x, y, d) {};
	Bird(int x, int y, int d, float velocity, TextureHolder* mTextures) :Object(x, y, d, velocity, mTextures) {};
	int type() { this->t = 4; return 4; }
	int getDirect() { return this->direct; }
	void draw();
	~Bird();
};

class Dinausor:public Object{
public:
    void move() {
		if (this->X == 1200)
			this->X = 0.0f;
		else
			this->X += this->velocity * (float)this->direct;
	};
	Dinausor(int x, int y, int d) : Object(x, y, d) {};
	Dinausor(int x, int y, int d, float velocity, TextureHolder* mTextures) :Object(x, y, d, velocity, mTextures) {};
	int type() { this->t = 5; return 5; }
	int getDirect() { return this->direct; }
	void draw();
	~Dinausor();
};
class Obstacle:public Object{
public:
	void move() { this->X += 0; this->Y += 0; };
	Obstacle(int x, int y, int d) : Object(x, y, d) {};
	Obstacle(int x, int y, int d, float velocity, TextureHolder* mTextures) :Object(x, y, d, velocity, mTextures) {};
	int type() { this->t = 1;return 1; }
	int getDirect() { return this->direct; }
	void draw();
	~Obstacle();
};
#endif