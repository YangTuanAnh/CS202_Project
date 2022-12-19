#include "Object.h"
#include "Player.hpp"
#include "program.h"

float Object::getX(){
    return this->X;
}
float Object::getY(){
    return this->Y;
}

void Dinausor::update() {
    this->move();
}

void Dinausor::draw() {
    Texture2D texture = mTextures->get(Textures::Dinasor);  // get texture
    if (this->direct == 1) {
        Vector2 pos = { this->X, this->Y };
        DrawTextureV(texture, pos, WHITE);
    }
    else {  // flip texture to the suitable direction
        Image inverseDirect = ImageCopy(LoadImageFromTexture(texture));
        ImageFlipHorizontal(&inverseDirect);
        Texture2D inverseTexture = LoadTextureFromImage(inverseDirect);
        // Color* pixels = LoadImageColors(inverseDirect);
        // UpdateTexture(inverseTexture, pixels);
        // UnloadImageColors(pixels);

        Vector2 pos = { this->X, this->Y };
        DrawTextureV(inverseTexture, pos, WHITE);
    }
    DrawRectangle(this->X, this->Y, texture.width, texture.height, RED);
}

void Car::update() {
    this->move();
}

Dinausor::~Dinausor(){
    this->direct = 0;
    this->X = 0;
    this->Y = 0;
}

void Car::draw() {
    Texture2D texture = mTextures->get(Textures::Car);  // get texture
    if (this->direct == 1) {
        Vector2 pos = { this->X, this->Y };
        DrawTextureV(texture, pos, WHITE);
    }
    else {  // flip texture to the suitable direction
        Image inverseDirect = ImageCopy(LoadImageFromTexture(texture));
        ImageFlipHorizontal(&inverseDirect);
        Texture2D inverseTexture = LoadTextureFromImage(inverseDirect);
        // Color* pixels = LoadImageColors(inverseDirect);
        // UpdateTexture(inverseTexture, pixels);
        // UnloadImageColors(pixels);

        Vector2 pos = { this->X, this->Y };
        DrawTextureV(inverseTexture, pos, WHITE);
    }
    DrawRectangle(this->X, this->Y, texture.width, texture.height, RED);
}

Car::~Car(){
    this->direct = 0;
    this->X = 0;
    this->Y = 0;
}

void Truck::update() {
    this->move();
}

void Truck::draw() {
    Texture2D texture = mTextures->get(Textures::Truck);  // get texture
    if (this->direct == 1) {
        Vector2 pos = { this->X, this->Y };
        DrawTextureV(texture, pos, WHITE);
    }
    else {  // flip texture to the suitable direction
        Image inverseDirect = ImageCopy(LoadImageFromTexture(texture));
        ImageFlipHorizontal(&inverseDirect);
        Texture2D inverseTexture = LoadTextureFromImage(inverseDirect);
        // Color* pixels = LoadImageColors(inverseDirect);
        // UpdateTexture(inverseTexture, pixels);
        // UnloadImageColors(pixels);

        Vector2 pos = { this->X, this->Y };
        DrawTextureV(inverseTexture, pos, WHITE);
    }
    DrawRectangle(this->X, this->Y, texture.width, texture.height, RED);
}

Truck::~Truck(){
    this->direct = 0;
    this->X = 0;
    this->Y = 0;
}

void Bird::update() {
    this->move();
}

void Bird::draw() {
    Texture2D texture = mTextures->get(Textures::Bird);  // get texture
    if (this->direct == 1) {
        Vector2 pos = { this->X, this->Y };
        DrawTextureV(texture, pos, WHITE);
    }
    else {  // flip texture to the suitable direction
        Image inverseDirect = ImageCopy(LoadImageFromTexture(texture));
        ImageFlipHorizontal(&inverseDirect);
        Texture2D inverseTexture = LoadTextureFromImage(inverseDirect);
        // Color* pixels = LoadImageColors(inverseDirect);
        // UpdateTexture(inverseTexture, pixels);
        // UnloadImageColors(pixels);

        Vector2 pos = { this->X, this->Y };
        DrawTextureV(inverseTexture, pos, WHITE);
    }
    DrawRectangle(this->X, this->Y, texture.width, texture.height, RED);
}

Bird::~Bird(){
    this->direct = 0;
    this->X = 0;
    this->Y = 0;
}

Object::~Object(){
    this->direct = 0;
    this->X = 0;
    this->Y = 0;
}

void Obstacle::update() {
    this->move();
}

void Obstacle::draw() {
    Texture2D texture = mTextures->get(Textures::Obstacle);  // get texture
    if (this->direct == 1) {
        Vector2 pos = { this->X, this->Y };
        DrawTextureV(texture, pos, WHITE);
    }
    else {  // flip texture to the suitable direction
        Image inverseDirect = ImageCopy(LoadImageFromTexture(texture));
        ImageFlipHorizontal(&inverseDirect);
        Texture2D inverseTexture = LoadTextureFromImage(inverseDirect);
        // Color* pixels = LoadImageColors(inverseDirect);
        // UpdateTexture(inverseTexture, pixels);
        // UnloadImageColors(pixels);
        Vector2 pos = { this->X, this->Y };
        DrawTextureV(inverseTexture, pos, WHITE);
    }
    DrawRectangle(this->X, this->Y, texture.width, texture.height, RED);
}
Obstacle::~Obstacle(){
    this->direct = 0;
    this->X = 0;
    this->Y = 0;
}