#include "Object.h"
#include "Player.h"
#include "program.h"

int Object::getX(){
    return this->X;
}
int Object::getY(){
    return this->Y;
}

void Dinausor::draw() {
    Texture2D texture = mTextures->get(Textures::Dinasor);  // get texture
    if (this->direct == 1) {
        BeginDrawing();

        DrawTexture(texture, this->X, this->Y, WHITE);

        EndDrawing();
    }
    else {  // flip texture to the suitable direction
        Image inverseDirect = ImageCopy(LoadImageFromTexture(texture));
        ImageFlipHorizontal(&inverseDirect);
        Texture2D inverseTexture = LoadTextureFromImage(inverseDirect);
        // Color* pixels = LoadImageColors(inverseDirect);
        // UpdateTexture(inverseTexture, pixels);
        // UnloadImageColors(pixels);

        BeginDrawing();

        DrawTexture(inverseTexture, this->X, this->Y, WHITE);

        EndDrawing();
    }
}

Dinausor::~Dinausor(){
    this->direct = 0;
    this->X = 0;
    this->Y = 0;
}

void Car::draw() {
    Texture2D texture = mTextures->get(Textures::Car);  // get texture
    if (this->direct == 1) {
        BeginDrawing();

        DrawTexture(texture, this->X, this->Y, WHITE);

        EndDrawing();
    }
    else {  // flip texture to the suitable direction
        Image inverseDirect = ImageCopy(LoadImageFromTexture(texture));
        ImageFlipHorizontal(&inverseDirect);
        Texture2D inverseTexture = LoadTextureFromImage(inverseDirect);
        // Color* pixels = LoadImageColors(inverseDirect);
        // UpdateTexture(inverseTexture, pixels);
        // UnloadImageColors(pixels);

        BeginDrawing();

        DrawTexture(inverseTexture, this->X, this->Y, WHITE);

        EndDrawing();
    }
}

Car::~Car(){
    this->direct = 0;
    this->X = 0;
    this->Y = 0;
}

void Truck::draw() {
    Texture2D texture = mTextures->get(Textures::Truck);  // get texture
    if (this->direct == 1) {
        BeginDrawing();

        DrawTexture(texture, this->X, this->Y, WHITE);

        EndDrawing();
    }
    else {  // flip texture to the suitable direction
        Image inverseDirect = ImageCopy(LoadImageFromTexture(texture));
        ImageFlipHorizontal(&inverseDirect);
        Texture2D inverseTexture = LoadTextureFromImage(inverseDirect);
        // Color* pixels = LoadImageColors(inverseDirect);
        // UpdateTexture(inverseTexture, pixels);
        // UnloadImageColors(pixels);

        BeginDrawing();

        DrawTexture(inverseTexture, this->X, this->Y, WHITE);

        EndDrawing();
    }
}

Truck::~Truck(){
    this->direct = 0;
    this->X = 0;
    this->Y = 0;
}

void Bird::draw() {
    Texture2D texture = mTextures->get(Textures::Bird);  // get texture
    if (this->direct == 1) {
        BeginDrawing();

        DrawTexture(texture, this->X, this->Y, WHITE);

        EndDrawing();
    }
    else {  // flip texture to the suitable direction
        Image inverseDirect = ImageCopy(LoadImageFromTexture(texture));
        ImageFlipHorizontal(&inverseDirect);
        Texture2D inverseTexture = LoadTextureFromImage(inverseDirect);
        // Color* pixels = LoadImageColors(inverseDirect);
        // UpdateTexture(inverseTexture, pixels);
        // UnloadImageColors(pixels);

        BeginDrawing();

        DrawTexture(inverseTexture, this->X, this->Y, WHITE);

        EndDrawing();
    }
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

void Obstacle::draw() {
    Texture2D texture = mTextures->get(Textures::Obstacle);  // get texture
    if (this->direct == 1) {
        BeginDrawing();

        DrawTexture(texture, this->X, this->Y, WHITE);

        EndDrawing();
    }
    else {  // flip texture to the suitable direction
        Image inverseDirect = ImageCopy(LoadImageFromTexture(texture));
        ImageFlipHorizontal(&inverseDirect);
        Texture2D inverseTexture = LoadTextureFromImage(inverseDirect);
        // Color* pixels = LoadImageColors(inverseDirect);
        // UpdateTexture(inverseTexture, pixels);
        // UnloadImageColors(pixels);

        BeginDrawing();

        DrawTexture(inverseTexture, this->X, this->Y, WHITE);

        EndDrawing();
    }
}
Obstacle::~Obstacle(){
    this->direct = 0;
    this->X = 0;
    this->Y = 0;
}