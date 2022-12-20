#include "Object.h"
#include "Player.hpp"

Object::Object(float x, float y, int d, Objects::ID type) {
    this->mX = x;
    this->mY = y;
	this->direction = d;
    this->type = type;
}

Object::Object(float x, float y, int d, float speed, TextureHolder *mTextures, Objects::ID type) {
	this->mX = x;
	this->mY = y;
	this->direction = d;
	this->speed = speed;
	this->mTextures = mTextures;
    this->type = type;
}

Car::Car(int x, int y, int d) : Object(x, y, d, Objects::Car) {}

Car::Car(int x, int y, int d, float speed, TextureHolder *mTextures) : Object(x, y, d, speed, mTextures, Objects::Car) {}

Truck::Truck(int x, int y, int d) : Object(x, y, d, Objects::Truck) {}

Truck::Truck(int x, int y, int d, float speed, TextureHolder *mTextures) : Object(x, y, d, speed, mTextures, Objects::Truck) {}

Bird::Bird(int x, int y, int d) : Object(x, y, d, Objects::Bird) {}

Bird::Bird(int x, int y, int d, float speed, TextureHolder *mTextures) : Object(x, y, d, speed, mTextures, Objects::Bird) {}

Dinosaur::Dinosaur(int x, int y, int d) : Object(x, y, d, Objects::Dinosaur) {}

Dinosaur::Dinosaur(int x, int y, int d, float speed, TextureHolder *mTextures) : Object(x, y, d, speed, mTextures, Objects::Dinosaur) {}

Obstacle::Obstacle(int x, int y, int d) : Object(x, y, d, Objects::Obstacle) {}

Obstacle::Obstacle(int x, int y, int d, float speed, TextureHolder *mTextures) : Object(x, y, d, speed, mTextures, Objects::Obstacle) {}

float Object::getX(){
    return this->mX;
}
float Object::getY(){
    return this->mY;
}

Objects::ID Object::getType() {
    return this->type;
}

int Object::getDirection() { 
    return this->direction;
}

void Object::update(float dt){
        this->mX += this->speed * dt * this->direction;
}

void Dinosaur::draw() {
    Texture2D texture = mTextures->get(Textures::Dinosaur);  // get texture
    if (this->direction == 1) {
        Vector2 pos = { this->mX, this->mY };
        DrawTextureV(texture, pos, WHITE);
    }
    else {  // flip texture to the suitable direction
        Image inverseDirect = ImageCopy(LoadImageFromTexture(texture));
        ImageFlipHorizontal(&inverseDirect);
        Texture2D inverseTexture = LoadTextureFromImage(inverseDirect);
        // Color* pixels = LoadImageColors(inverseDirect);
        // UpdateTexture(inverseTexture, pixels);
        // UnloadImageColors(pixels);

        Vector2 pos = { this->mX, this->mY };
        DrawTextureV(inverseTexture, pos, WHITE);
    }
}

Dinosaur::~Dinosaur(){
    this->direction = 0;
    this->mX = 0;
    this->mY = 0;
Dinausor::~Dinausor(){
    this->direct = 0;
    this->X = 0;
    this->Y = 0;
}

void Car::draw() {
    Texture2D texture = mTextures->get(Textures::Car);  // get texture
    if (this->direction == 1) {
        Vector2 pos = { this->mX, this->mY };
        DrawTextureV(texture, pos, WHITE);
    }
    else {  // flip texture to the suitable direction
        Image inverseDirect = ImageCopy(LoadImageFromTexture(texture));
        ImageFlipHorizontal(&inverseDirect);
        Texture2D inverseTexture = LoadTextureFromImage(inverseDirect);
        // Color* pixels = LoadImageColors(inverseDirect);
        // UpdateTexture(inverseTexture, pixels);
        // UnloadImageColors(pixels);

        Vector2 pos = { this->mX, this->mY };
        DrawTextureV(inverseTexture, pos, WHITE);
    }
}

Car::~Car(){
    this->direction = 0;
    this->mX = 0;
    this->mY = 0;
}

void Truck::draw() {
    Texture2D texture = mTextures->get(Textures::Truck);  // get texture
    if (this->direction == 1) {
        Vector2 pos = { this->mX, this->mY };
        DrawTextureV(texture, pos, WHITE);
    }
    else {  // flip texture to the suitable direction
        Image inverseDirect = ImageCopy(LoadImageFromTexture(texture));
        ImageFlipHorizontal(&inverseDirect);
        Texture2D inverseTexture = LoadTextureFromImage(inverseDirect);
        // Color* pixels = LoadImageColors(inverseDirect);
        // UpdateTexture(inverseTexture, pixels);
        // UnloadImageColors(pixels);

        Vector2 pos = { this->mX, this->mY };
        DrawTextureV(inverseTexture, pos, WHITE);
    }
}

Truck::~Truck(){
    this->direction = 0;
    this->mX = 0;
    this->mY = 0;
}

void Bird::draw() {
    Texture2D texture = mTextures->get(Textures::Bird);  // get texture
    if (this->direction == 1) {
        Vector2 pos = { this->mX, this->mY };
        DrawTextureV(texture, pos, WHITE);
    }
    else {  // flip texture to the suitable direction
        Image inverseDirect = ImageCopy(LoadImageFromTexture(texture));
        ImageFlipHorizontal(&inverseDirect);
        Texture2D inverseTexture = LoadTextureFromImage(inverseDirect);
        // Color* pixels = LoadImageColors(inverseDirect);
        // UpdateTexture(inverseTexture, pixels);
        // UnloadImageColors(pixels);

        Vector2 pos = { this->mX, this->mY };
        DrawTextureV(inverseTexture, pos, WHITE);
    }
}

Bird::~Bird(){
    this->direction = 0;
    this->mX = 0;
    this->mY = 0;

}
Object::~Object(){
    this->direction = 0;
    this->mX = 0;
    this->mY = 0;
}

void Obstacle::draw() {
    Texture2D texture = mTextures->get(Textures::Obstacle);  // get texture
    if (this->direction == 1) {
        Vector2 pos = { this->mX, this->mY };
        DrawTextureV(texture, pos, WHITE);
    }
    else {  // flip texture to the suitable direction
        Image inverseDirect = ImageCopy(LoadImageFromTexture(texture));
        ImageFlipHorizontal(&inverseDirect);
        Texture2D inverseTexture = LoadTextureFromImage(inverseDirect);
        // Color* pixels = LoadImageColors(inverseDirect);
        // UpdateTexture(inverseTexture, pixels);
        // UnloadImageColors(pixels);
        Vector2 pos = { this->mX, this->mY };
        DrawTextureV(inverseTexture, pos, WHITE);
    }
}

Obstacle::~Obstacle(){
    this->direction = 0;
    this->mX = 0;
    this->mY = 0;
}