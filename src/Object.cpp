#include "Object.h"
#include "Player.hpp"

Object::Object(float x, float y, int d, ObjectTypes::ID type) {
    this->mX = x;
    this->mY = y;
	this->direction = d;
    this->type = type;
}

Object::Object(float x, float y, int d, float velocity, TextureHolder *mTextures, ObjectTypes::ID type) {
	this->mX = x;
	this->mY = y;
	this->direction = d;
	this->velocity = velocity;
	this->mTextures = mTextures;
    this->type = type;
}

Vector2 Object::convertCar2IsoVector(Vector2 Cartesian) {
    Vector2 isometricVector;
    isometricVector.x = Cartesian.x - Cartesian.y + WIDTH/2;
    // if (Cartesian.x > 0)
    //     Cartesian.y += Cartesian.x/2;
    // else if (Cartesian.x == 0)
    //     Cartesian.y /= 2;
    isometricVector.y = (Cartesian.x + Cartesian.y)/2;
    return isometricVector;
}

Car::Car(int x, int y, int d) : Object(x, y, d, ObjectTypes::Car) {
    this->velocity = V_CAR_N;
}

Car::Car(int x, int y, int d, float velocity, TextureHolder *mTextures) : Object(x, y, d, velocity, mTextures, ObjectTypes::Car) {}

Truck::Truck(int x, int y, int d) : Object(x, y, d, ObjectTypes::Truck) {
    this->velocity = V_TRUCK_N;
}

Truck::Truck(int x, int y, int d, float velocity, TextureHolder *mTextures) : Object(x, y, d, velocity, mTextures, ObjectTypes::Truck) {}

Bird::Bird(int x, int y, int d) : Object(x, y, d, ObjectTypes::Bird) {
    this->velocity = V_BIRD_N;
}

Bird::Bird(int x, int y, int d, float velocity, TextureHolder *mTextures) : Object(x, y, d, velocity, mTextures, ObjectTypes::Bird) {}

Dinosaur::Dinosaur(int x, int y, int d) : Object(x, y, d, ObjectTypes::Dinosaur) {
    this->velocity = V_DINOSAUR_N;
}

Dinosaur::Dinosaur(int x, int y, int d, float velocity, TextureHolder *mTextures) : Object(x, y, d, velocity, mTextures, ObjectTypes::Dinosaur) {}

Obstacle::Obstacle(int x, int y, int d) : Object(x, y, d, ObjectTypes::Obstacle) {
    this->velocity = V_OBSTACLE;
}

Obstacle::Obstacle(int x, int y, int d, float velocity, TextureHolder *mTextures) : Object(x, y, d, velocity, mTextures, ObjectTypes::Obstacle) {}

float Object::getX(){
    return this->mX;
}
float Object::getY(){
    return this->mY;
}

ObjectTypes::ID Object::getType() {
    return this->type;
}

int Object::getDirection() { 
    return this->direction;
}

void Object::update(float dt){
    this->mX += this->velocity * dt * this->direction;
}

void Dinosaur::draw() {
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
    Vector2 pos = this->convertCar2IsoVector({ this->mX, this->mY });
    DrawTextureV(texture, pos, WHITE);
    // DrawRectangle(this->mX, this->mY, texture.width, texture.height, RED);
}

Dinosaur::~Dinosaur(){
    this->direction = 0;
    this->mX = 0;
    this->mY = 0;
}

void Car::draw() {
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
    Vector2 pos = this->convertCar2IsoVector({ this->mX, this->mY - 10.0f });
    DrawTextureV(texture, pos, WHITE);
    // DrawRectangle(this->mX, this->mY, texture.width, texture.height, RED);
}

Car::~Car(){
    this->direction = 0;
    this->mX = 0;
    this->mY = 0;
}

void Truck::draw() {
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
    Vector2 pos = this->convertCar2IsoVector({ this->mX, this->mY - 20.0f });
    DrawTextureV(texture, pos, WHITE);
    // DrawRectangle(this->mX, this->mY, texture.width, texture.height, RED);
}

Truck::~Truck(){
    this->direction = 0;
    this->mX = 0;
    this->mY = 0;
}

void Bird::draw() {
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
    Vector2 pos = this->convertCar2IsoVector({ this->mX, this->mY });
    DrawTextureV(texture, pos, WHITE);
    // DrawRectangle(this->mX, this->mY, texture.width, texture.height, RED);
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
    // if (this->direction == 1) {
    // }
    // else {  // flip texture to the suitable direction
    //     // Color* pixels = LoadImageColors(inverseDirect);
    //     // UpdateTexture(inverseTexture, pixels);
    //     // UnloadImageColors(pixels);
    // }
    Vector2 pos = this->convertCar2IsoVector({ this->mX, this->mY });
    DrawTextureV(texture, pos, WHITE);
    // DrawRectangle(this->mX, this->mY, texture.width, texture.height, RED);
}

Obstacle::~Obstacle(){
    this->direction = 0;
    this->mX = 0;
    this->mY = 0;
}