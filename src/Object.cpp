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

void Object::saveThis(std::ofstream& out) {
    // out << "Object: ";
    out << (int)this->type << ' ' << this->mX << ' ' << this->mY << '\n';
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
    this->pos = convertCar2IsoVector({ this->mX, this->mY });
    this->pos.x -= 31.0f;
    this->pos.y -= 70.0f;
}

Obstacle::Obstacle(int x, int y, int d, float speed, TextureHolder *mTextures) : Object(x, y, d, speed, mTextures, Objects::Obstacle) {
    // this->mX++;
    this->pos = convertCar2IsoVector({ this->mX, this->mY });
    this->pos.x -= 31.0f;
    this->pos.y -= 70.0f;
}

TrafficLamp::TrafficLamp(int x, int y, int d) : Object(x, y, d, Objects::TrafficLamp) {
    this->nextStateTime = GetRandomValue(0, LAMP_TIME)*FPS;
    this->states = TrafficLampStates::ID(GetRandomValue(0, 3));
    this->pos = convertCar2IsoVector({ this->mX, this->mY });
    this->pos.x+=52.f;
    this->pos.y-=32.f;
}

TrafficLamp::TrafficLamp(int x, int y, int d, float speed, TextureHolder *mTextures) : Object(x, y, d, speed, mTextures, Objects::TrafficLamp) {
    this->nextStateTime = GetRandomValue(0, LAMP_TIME)*FPS;
    this->states = TrafficLampStates::ID(GetRandomValue(0, 3));
    this->pos = convertCar2IsoVector({ this->mX, this->mY });
    this->pos.x+=32.f;
    this->pos.y-=22.f;
}

float Object::getX(){
    return this->mX;
}
float Object::getY(){
    return this->mY;
}

void Object::setSpeed(float sp) {
    this->speed = sp;
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

TrafficLampStates::ID Object::getLampState() {
    return TrafficLampStates::ID::Green;
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
    this->pos = convertCar2IsoVector({ this->mX, this->mY });
}

void Dinosaur::drawThis() {
    Texture2D texture;
    if (this->direction == 1) {
        texture = mTextures->get(Textures::Dinosaur_right);  // get texture
        this->pos.x -= 50.0f;
        this->pos.y -= 30.0f;
    }
    else {  // flip texture to the suitable direction
        texture = mTextures->get(Textures::Dinosaur_left);  // get texture
        this->pos.x -= 25.0f;
        this->pos.y -= 25.0f;
        // Image inverseDirect = ImageCopy(LoadImageFromTexture(texture));
        // ImageFlipHorizontal(&inverseDirect);
        // Texture2D inverseTexture = LoadTextureFromImage(inverseDirect);
        // Color* pixels = LoadImageColors(inverseDirect);
        // UpdateTexture(inverseTexture, pixels);
        // UnloadImageColors(pixels);
    }
    //DrawRectanglePro(Rectangle{pos.x+10.0f,pos.y+5.0f,85.0f,35.0f},{0,0},29.0f,RED);
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
    this->pos = convertCar2IsoVector({ this->mX, this->mY });
}

void Car::drawThis() {
    Texture2D texture;
    if (this->direction == 1) {
        texture = mTextures->get(Textures::Car_right);  // get texture
        this->pos.x -= 25.0f;
        this->pos.y -= 5.0f;
    }
    else {  // flip texture to the suitable direction
        texture = mTextures->get(Textures::Car_left);  // get texture
        this->pos.x -= 25.0f;
        this->pos.y -= 5.0f;
        // Image inverseDirect = ImageCopy(LoadImageFromTexture(texture));
        // ImageFlipHorizontal(&inverseDirect);
        // Texture2D inverseTexture = LoadTextureFromImage(inverseDirect);
        // Color* pixels = LoadImageColors(inverseDirect);
        // UpdateTexture(inverseTexture, pixels);
        // UnloadImageColors(pixels);
    }

    //DrawRectanglePro(Rectangle{pos.x+10.0f,pos.y-3.0f,40.0f,35.0f},{0,0},28.0f,RED);
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
    this->pos = convertCar2IsoVector({ this->mX, this->mY });
}

void Truck::drawThis() {
    Texture2D texture;
    if (this->direction == 1) {
        texture = mTextures->get(Textures::Truck_right);  // get texture
        this->pos.x -= 50.0f;
        this->pos.y -= 30.0f;
    }
    else {  // flip texture to the suitable direction
        texture = mTextures->get(Textures::Truck_left);  // get texture
        this->pos.x -= 20.0f;
        this->pos.y -= 10.0f;
        // Image inverseDirect = ImageCopy(LoadImageFromTexture(texture));
        // ImageFlipHorizontal(&inverseDirect);
        // Texture2D inverseTexture = LoadTextureFromImage(inverseDirect);
        // Color* pixels = LoadImageColors(inverseDirect);
        // UpdateTexture(inverseTexture, pixels);
        // UnloadImageColors(pixels);
    }
    //DrawRectanglePro(Rectangle{pos.x+10.0f,pos.y,40.0f,35.0f},{0,0},29.0f,RED);
    DrawTextureV(texture, this->pos, WHITE);
}

Truck::~Truck(){
    this->direction = 0;
    this->mX = 0;
    this->mY = 0;
}

void Bird::updateThis(float dt) {
    this->mX += this->speed * dt * this->direction;
    this->pos = convertCar2IsoVector({ this->mX, this->mY });
}

void Bird::drawThis() {
    Texture2D texture;
    if (this->direction == 1) {
        texture = mTextures->get(Textures::Bird_right);  // get texture
        this->pos.x -= 20.0f;
        this->pos.y -= 30.0f;
    }
    else {  // flip texture to the suitable direction
        texture = mTextures->get(Textures::Bird_left);  // get texture
        this->pos.x -= 10.0f;
        this->pos.y -= 25.0f;
        // Image inverseDirect = ImageCopy(LoadImageFromTexture(texture));
        // ImageFlipHorizontal(&inverseDirect);
        // Texture2D inverseTexture = LoadTextureFromImage(inverseDirect);
        // Color* pixels = LoadImageColors(inverseDirect);
        // UpdateTexture(inverseTexture, pixels);
        // UnloadImageColors(pixels);
    }
    //DrawRectanglePro(Rectangle{pos.x+10.0f,pos.y,40.0f,35.0f},{0,0},29.0f,RED);
    DrawTextureV(texture, this->pos, WHITE);
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
    // pos.y -= texture.height*0.25;
    // if (this->mX>=0 && this->mX<MAP_WIDTH*BLOCK_SIZE)
    //     DrawRectanglePro(Rectangle{pos.x+30.0f,pos.y+65.0f,40.0f,38.0f},{0,0},29.0f,RED);
    if (this->mX>=0 && this->mX<MAP_WIDTH*BLOCK_SIZE)
        DrawTextureV(texture, this->pos, WHITE);
    else DrawTextureV(texture, this->pos, GRAY);
    // DrawRectangle(this->mX, this->mY, texture.width, texture.height, RED);
}

Obstacle::~Obstacle(){
    this->direction = 0;
    this->mX = 0;
    this->mY = 0;
};

void TrafficLamp::drawThis() {
    Texture2D texture;
    switch (this->states) {
        case TrafficLampStates::ID::Green:
            texture = mTextures->get(Textures::TrafficLamp_green);
            break;
        case TrafficLampStates::ID::Yellow:
            texture = mTextures->get(Textures::TrafficLamp_yellow);
            break;
        case TrafficLampStates::ID::Red:
            texture = mTextures->get(Textures::TrafficLamp_red);
            break;
        default:
            break;
    }
      // get texture
    // if (this->direction == 1) {
    // }
    // else {  // flip texture to the suitable direction
    //     // Color* pixels = LoadImageColors(inverseDirect);
    //     // UpdateTexture(inverseTexture, pixels);
    //     // UnloadImageColors(pixels);
    // }
    // pos.y -= texture.height*0.25;
    DrawTexture(texture, (int)pos.x, (int)pos.y, WHITE);
    // DrawRectangle(this->mX, this->mY, texture.width, texture.height, RED);
}

void TrafficLamp::updateThis(float dt) {
    if (nextStateTime--) return;
    switch (states) {
        case TrafficLampStates::ID::Green:
            states = TrafficLampStates::ID::Yellow;
            nextStateTime = LAMP_TIME * FPS / 2;
            break;
        case TrafficLampStates::ID::Yellow:
            states = TrafficLampStates::ID::Red;
            nextStateTime = LAMP_TIME * FPS;
            break;
        case TrafficLampStates::ID::Red:
            states = TrafficLampStates::ID::Green;
            nextStateTime = LAMP_TIME * FPS;
            break;
    }
}

TrafficLamp::~TrafficLamp(){
    this->direction = 0;
    this->mX = 0;
    this->mY = 0;
};

TrafficLampStates::ID TrafficLamp::getLampState() {
    return this->states;
}