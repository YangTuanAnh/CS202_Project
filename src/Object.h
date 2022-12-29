#pragma once
#include <memory>

#include "Global.h"
#include "TextureHolder.h"
#include "ResourceIdentifiers.hpp"
#include "SceneNode.h"

class Object : public SceneNode {
protected:
	float mX, mY;
	// 1: right, -1: left
	Vector2 pos;
	int direction = 1;
	float speed;
	Objects::ID type;
	TextureHolder *mTextures;

public:
    //set up obstacle
	typedef std::unique_ptr<Object> Ptr;
	// get info
	float getX();
	float getY();

	// set up obstacle
	virtual Objects::ID getType();
	int getDirection();
	Object(float x, float y, int d, Objects::ID type);
	Object(float x, float y, int d, float speed, TextureHolder *mTextures, Objects::ID type);
	virtual void updateThis(float dt);
	virtual void drawThis() = 0;
	virtual ~Object();
};

class Car : public Object {
public:
	Car(int x, int y, int d);
	Car(int x, int y, int d, float speed, TextureHolder *mTextures);
	void updateThis(float dt);
	void drawThis();
	~Car();
};

class Truck : public Object {
public:
	Truck(int x, int y, int d);
	Truck(int x, int y, int d, float speed, TextureHolder *mTextures);
	void updateThis(float dt);
	void drawThis();
	~Truck();
};

class Bird : public Object {
public:
	Bird(int x, int y, int d);
	Bird(int x, int y, int d, float speed, TextureHolder *mTextures);
	void updateThis(float dt);
	void drawThis();
	~Bird();
};

class Dinosaur : public Object {
public:
	Dinosaur(int x, int y, int d);
	Dinosaur(int x, int y, int d, float speed, TextureHolder *mTextures);
	void updateThis(float dt);
	void drawThis();
	~Dinosaur();
};

class Obstacle : public Object {
public:
	Obstacle(int x, int y, int d);
	Obstacle(int x, int y, int d, float speed, TextureHolder *mTextures);
	// void updateThis(float dt);
	void drawThis();
	~Obstacle();
};