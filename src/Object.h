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
#define V_DINOSAUR_N 1.5f

class Object {
protected:
	float mX, mY;
	// 1: right, -1: left
	int direction = 1;
	float velocity;
	ObjectTypes::ID type;
	TextureHolder *mTextures;

public:
    //set up obstacle
	typedef std::unique_ptr<Object> Ptr;
	// get info
	float getX();
	float getY();

	// set up obstacle
	virtual ObjectTypes::ID getType();
	int getDirection();
	Object(float x, float y, int d, ObjectTypes::ID type);
	Object(float x, float y, int d, float velocity, TextureHolder *mTextures, ObjectTypes::ID type);
	void update(float dt);
	Vector2 convertCar2IsoVector(Vector2 Cartesian);
	virtual void draw() = 0;
	virtual ~Object();
};

class Car : public Object {
public:
	// ObjectTypes::ID getType();
	void update(float dt);
	Car(int x, int y, int d);
	Car(int x, int y, int d, float velocity, TextureHolder *mTextures);
	// void update(float dt);
	void draw();
	~Car();
};

class Truck : public Object {
public:
	// ObjectTypes::ID getType();
	void update(float dt);
	Truck(int x, int y, int d);
	Truck(int x, int y, int d, float velocity, TextureHolder *mTextures);
	// void update(float dt);
	void draw();
	~Truck();
};

class Bird : public Object {
public:
	// ObjectTypes::ID getType();
	void update(float dt);
	Bird(int x, int y, int d);
	Bird(int x, int y, int d, float velocity, TextureHolder *mTextures);
	void draw();
	~Bird();
};

class Dinosaur : public Object {
public:
	// ObjectTypes::ID getType();
	void update(float dt);
	Dinosaur(int x, int y, int d);
	Dinosaur(int x, int y, int d, float velocity, TextureHolder *mTextures);
	// void update(float dt);
	void draw();
	~Dinosaur();
};

class Obstacle : public Object {
public:
	// ObjectTypes::ID getType();
	void update(float dt);
	Obstacle(int x, int y, int d);
	Obstacle(int x, int y, int d, float velocity, TextureHolder *mTextures);
	// void update(float dt);
	void draw();
	~Obstacle();
};
#endif