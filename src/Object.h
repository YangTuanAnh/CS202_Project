#pragma once
#include <memory>

#include "Global.h"
#include "TextureHolder.h"
#include "ResourceIdentifiers.hpp"

class Object {
protected:
	float mX, mY;
	// 1: right, -1: left
	int direction = 1;
	float speed;
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
	Object(float x, float y, int d, float speed, TextureHolder *mTextures, Objects::ID type);
	virtual void update(float dt);
	virtual void draw() = 0;
	virtual ~Object();
};

class Car : public Object {
public:
	Car(int x, int y, int d);
	Car(int x, int y, int d, float speed, TextureHolder *mTextures);
	// void update(float dt);
	void draw();
	~Car();
};

class Truck : public Object {
public:
	Truck(int x, int y, int d);
	Truck(int x, int y, int d, float speed, TextureHolder *mTextures);
	// void update(float dt);
	void draw();
	~Truck();
};

class Bird : public Object {
public:
	Bird(int x, int y, int d);
	Bird(int x, int y, int d, float speed, TextureHolder *mTextures);
	// void update(float dt);
	void draw();
	~Bird();
};

class Dinosaur : public Object {
public:
	Dinosaur(int x, int y, int d);
	Dinosaur(int x, int y, int d, float speed, TextureHolder *mTextures);
	// void update(float dt);
	void draw();
	~Dinosaur();
};
class Obstacle : public Object {
public:
	Obstacle(int x, int y, int d);
	Obstacle(int x, int y, int d, float speed, TextureHolder *mTextures);
	// void update(float dt);
	void draw();
	~Obstacle();
};