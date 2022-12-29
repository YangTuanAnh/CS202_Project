#include "Object.h"
#include "Player.hpp"
#include "program.h"

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

Car::Car(int x, int y, int d) : Object(x, y, d, Objects::Car) {
}

Car::Car(int x, int y, int d, float speed, TextureHolder *mTextures) : Object(x, y, d, speed, mTextures, Objects::Car) {}

Truck::Truck(int x, int y, int d) : Object(x, y, d, Objects::Truck) {
}

Truck::Truck(int x, int y, int d, float speed, TextureHolder *mTextures) : Object(x, y, d, speed, mTextures, Objects::Truck) {}

Bird::Bird(int x, int y, int d) : Object(x, y, d, Objects::Bird) {
}

Bird::Bird(int x, int y, int d, float speed, TextureHolder *mTextures) : Object(x, y, d, speed, mTextures, Objects::Bird) {}

Dinosaur::Dinosaur(int x, int y, int d) : Object(x, y, d, Objects::Dinosaur) {
}

Dinosaur::Dinosaur(int x, int y, int d, float speed, TextureHolder *mTextures) : Object(x, y, d, speed, mTextures, Objects::Dinosaur) {}

Obstacle::Obstacle(int x, int y, int d) : Object(x, y, d, Objects::Obstacle) {
}

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

void Object::updateThis(float dt){
    this->mX += this->speed * dt * this->direction;
}

Object::~Object(){
    this->direction = 0;
    this->mX = 0;
    this->mY = 0;
}

void Dinosaur::updateThis(float dt) {
    float displacement = this->speed * dt * (float)this->direction;
    this->mX += displacement;
    // pos = Vector2{ this->mX, this->mY };
    pos = convertCar2IsoVector({ this->mX, this->mY });
    pos.x -= 50.0f;
    pos.y -= 30.0f;
}

void Dinosaur::drawThis() {
    Texture2D texture;
    if (this->direction == 1) {
        texture = mTextures->get(Textures::Dinosaur_right);  // get texture
    }
    else {  // flip texture to the suitable direction
        texture = mTextures->get(Textures::Dinosaur_left);  // get texture
        // Image inverseDirect = ImageCopy(LoadImageFromTexture(texture));
        // ImageFlipHorizontal(&inverseDirect);
        // Texture2D inverseTexture = LoadTextureFromImage(inverseDirect);
        // Color* pixels = LoadImageColors(inverseDirect);
        // UpdateTexture(inverseTexture, pixels);
        // UnloadImageColors(pixels);
    }
    DrawTextureV(texture, pos, WHITE);
    // DrawRectangle(this->mX, this->mY, texture.width, texture.height, RED);
}

Dinosaur::~Dinosaur() {
    this->direction = 0;
    this->mX = 0;
    this->mY = 0;
}

void Car::updateThis(float dt) {
    this->mX += this->speed * dt * this->direction;
    pos = convertCar2IsoVector({ this->mX, this->mY });
    pos.x -= 28.0f;
    pos.y -= 5.0f;
}

void Car::drawThis() {
    Texture2D texture;
    if (this->direction == 1) {
        texture = mTextures->get(Textures::Car_right);  // get texture
    }
    else {  // flip texture to the suitable direction
        texture = mTextures->get(Textures::Car_left);  // get texture
        // Image inverseDirect = ImageCopy(LoadImageFromTexture(texture));
        // ImageFlipHorizontal(&inverseDirect);
        // Texture2D inverseTexture = LoadTextureFromImage(inverseDirect);
        // Color* pixels = LoadImageColors(inverseDirect);
        // UpdateTexture(inverseTexture, pixels);
        // UnloadImageColors(pixels);
    }
    DrawTextureV(texture, pos, WHITE);
    // DrawRectangle(this->mX, this->mY, texture.width, texture.height, RED);
}

Car::~Car() {
    this->direction = 0;
    this->mX = 0;
    this->mY = 0;
}

void Truck::updateThis(float dt) {
    this->mX += this->speed * dt * this->direction;
    Vector2 pos = convertCar2IsoVector({ this->mX, this->mY });
    pos.x -= 46.0f;
    pos.y -= 25.0f;
}

void Truck::drawThis() {
    Texture2D texture;
    if (this->direction == 1) {
        texture = mTextures->get(Textures::Truck_right);  // get texture
    }
    else {  // flip texture to the suitable direction
        texture = mTextures->get(Textures::Truck_left);  // get texture
        // Image inverseDirect = ImageCopy(LoadImageFromTexture(texture));
        // ImageFlipHorizontal(&inverseDirect);
        // Texture2D inverseTexture = LoadTextureFromImage(inverseDirect);
        // Color* pixels = LoadImageColors(inverseDirect);
        // UpdateTexture(inverseTexture, pixels);
        // UnloadImageColors(pixels);
    }
    DrawTextureV(texture, pos, WHITE);
    // DrawRectangle(this->mX, this->mY, texture.width, texture.height, RED);
}

Truck::~Truck(){
    this->direction = 0;
    this->mX = 0;
    this->mY = 0;
}

void Bird::updateThis(float dt) {
    this->mX += this->speed * dt * this->direction;
    Vector2 pos = convertCar2IsoVector({ this->mX, this->mY });
    pos.x -= 20.0f;
    pos.y -= 10.0f;
}

void Bird::drawThis() {
    Texture2D texture;
    if (this->direction == 1) {
        texture = mTextures->get(Textures::Bird_right);  // get texture
    }
    else {  // flip texture to the suitable direction
        texture = mTextures->get(Textures::Bird_left);  // get texture
        // Image inverseDirect = ImageCopy(LoadImageFromTexture(texture));
        // ImageFlipHorizontal(&inverseDirect);
        // Texture2D inverseTexture = LoadTextureFromImage(inverseDirect);
        // Color* pixels = LoadImageColors(inverseDirect);
        // UpdateTexture(inverseTexture, pixels);
        // UnloadImageColors(pixels);
    }
    DrawTextureV(texture, pos, WHITE);
    // DrawRectangle(this->mX, this->mY, texture.width, texture.height, RED);
}

Bird::~Bird(){
    this->direction = 0;
    this->mX = 0;
    this->mY = 0;

}

void Obstacle::drawThis() {
    Texture2D texture = mTextures->get(Textures::Obstacle);  // get texture
    // if (this->direction == 1) {
    // }
    // else {  // flip texture to the suitable direction
    //     // Color* pixels = LoadImageColors(inverseDirect);
    //     // UpdateTexture(inverseTexture, pixels);
    //     // UnloadImageColors(pixels);
    // }
    Vector2 pos = convertCar2IsoVector({ this->mX, this->mY });
    // pos.y -= texture.height*0.25;
    DrawTextureV(texture, pos, WHITE);
    // DrawRectangle(this->mX, this->mY, texture.width, texture.height, RED);
}

Obstacle::~Obstacle(){
    this->direction = 0;
    this->mX = 0;
    this->mY = 0;
}