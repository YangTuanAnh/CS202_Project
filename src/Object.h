#ifndef OBJECT_H
#define OBJECT_H

#include <memory>

#include "Global.h"
#include "TextureHolder.h"
#include "ResourceIdentifiers.hpp"

// Object velocity define
#define V_OBSTACLE 0.0f

// normal mode
#define V_CAR_N 2.0f
#define V_TRUCK_N 2.5f
#define V_BIRD_N 3.5f
#define V_DINAUSOR_N 1.5f

class Object {
protected:
	float mX, mY;
	// 1: right, -1: left
	int direction = 1;
	float velocity;
	Objects::ID type;
	TextureHolder *mTextures;

public:
	typedef std::unique_ptr<Object> Ptr;
	// get info
	float getX();
	float getY();

	// set up obstacle
	virtual Objects::ID getType();
	int getDirection();
	Object(float x, float y, int d, Objects::ID type);
	Object(float x, float y, int d, float velocity, TextureHolder *mTextures, Objects::ID type);
	virtual void update(float dt);
	virtual void draw() = 0;
	virtual ~Object();
};

class Car : public Object {
public:
	Car(int x, int y, int d);
	Car(int x, int y, int d, float velocity, TextureHolder *mTextures);
	// void update(float dt);
	void draw();
	~Car();
};

class Truck : public Object {
public:
	Truck(int x, int y, int d);
	Truck(int x, int y, int d, float velocity, TextureHolder *mTextures);
	// void update(float dt);
	void draw();
	~Truck();
};

class Bird : public Object {
public:
	Bird(int x, int y, int d);
	Bird(int x, int y, int d, float velocity, TextureHolder *mTextures);
	// void update(float dt);
	void draw();
	~Bird();
};

class Dinosaur : public Object {
public:
	Dinosaur(int x, int y, int d);
	Dinosaur(int x, int y, int d, float velocity, TextureHolder *mTextures);
	// void update(float dt);
	void draw();
	~Dinosaur();
};
class Obstacle : public Object {
public:
	Obstacle(int x, int y, int d);
	Obstacle(int x, int y, int d, float velocity, TextureHolder *mTextures);
	// void update(float dt);
	void draw();
	~Obstacle();
};
#endif