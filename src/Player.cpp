#include "Player.hpp"

#include <cassert>
#include <iostream>

#define PLAYER_BASE_SIZE 40.0f
#define PLAYER_SPEED 40.0f

Player::Player() {
    std::cerr << "Player constructor" << std::endl;
    this->mX = 10 * BLOCK_SIZE;
    this->mY = -10 * BLOCK_SIZE;
    this->point = 0;
}

Player::Player(float mX, float mY, int Point) {
    std::cerr << "Player constructor" << std::endl;
    this->mX = mX;
    this->mY = mY;
    this->point = Point;
}

void Player::init(TextureHolder *mTextures) {
    this->mTextures = mTextures;
    chicken = &(this->mTextures->get(Textures::Player_down));
    mState = createState(PlayerStates::Idle);
}

void Player::reset() {
    this->mX = 10 * BLOCK_SIZE;
    this->mY = -10 * BLOCK_SIZE;
    this->point = 0;
    this->mState = createState(PlayerStates::Idle);
}

PlayerState::Ptr Player::createState(PlayerStates::ID stateID) {
    auto found = mFactories.find(stateID);
    assert(found != mFactories.end());
    return found->second();
}

float Player::getX() {
    return this->mX;
}

float Player::getY() {
    return this->mY;
}

Vector2 Player::getPos() {
    return Vector2{this->mX, this->mY};
}

void Player::setState(PlayerStates::ID id) {
    mState = createState(id);
}

void Player::drawThis() {
    // ClearBackground(RAYWHITE);
    if (!this->isDead()) {
        int frameWidth = chicken->width;
        int frameHeight = chicken->height;
        Rectangle source = {0.0f, 0.0f, (float)frameWidth, (float)frameHeight};
        Vector2 position = convertCar2IsoVector({ this->mX, this->mY });
        position.x -= 15.0f;
        position.y -= 10.0f;
        switch (this->mState->stateID) {
        case PlayerStates::Idle:
        case PlayerStates::Jumping:
            DrawTextureRec(*chicken, source, position, WHITE);
            break;
        default:
            break;
        }
        DrawRectangleLines(position.x,position.y+20.0f,40.0f,40.0f,RED);
        
        // DrawRectangle(this->mX,this->mY,PLAYER_BASE_SIZE,PLAYER_BASE_SIZE,RED);
    }
}

void Player::updateThis(float dt) {
    mState->update(dt);
}

bool Player::collision(Object *ob) {
    float X = ob->getX();
    float Y = ob->getY();
    if (ob->getType()==Objects::Dinosaur){
        if((this->mY==Y)&&((this->mX >= X && this->mX <= X+40.0f)||(this->mX+40.0f >= X && this->mX+40.0f <=X+40.0f)))//size is 60x40
            return true;
        if((this->mY > Y&&this->mY<Y+40.0f) && ((this->mX > X&&this->mX <X+40.0f)||(this->mX+40.0f > X&&this->mX+40.0f <X+40.0f)))//size is 60x40
            return true;
        if((this->mY < Y&&this->mY>Y-40.0f) && ((this->mX > X&&this->mX <X+40.0f)||(this->mX+40.0f > X&&this->mX+40.0f <X+40.0f)))//size is 60x40
            return true;
    }

    if (ob->getType()==Objects::Bird){
        if(((this->mY==Y)&&((this->mX > X&&this->mX <X+40.0f)||(this->mX+40.0f > X&&this->mX+40.0f <X+40.0f))))//size is 40x40
            return true;
        if((this->mY > Y&&this->mY<Y+40.0f) && ((this->mX > X&&this->mX <X+40.0f)||(this->mX+40.0f > X&&this->mX+40.0f <X+40.0f)))//size is 40x40
            return true;
        if((this->mY < Y&&this->mY>Y-40.0f) && ((this->mX > X&&this->mX <X+40.0f)||(this->mX+40.0f > X&&this->mX+40.0f <X+40.0f)))//size is 40x40
            return true;
    }

    if (ob->getType()==Objects::Car){
        if(((this->mY==Y)&&((this->mX > X&&this->mX <X+20.0f)||(this->mX+40.0f > X&&this->mX+40.0f <X+20.0f))))//size is 40x40
            return true;
        if((this->mY > Y&&this->mY<Y+40.0f) && ((this->mX > X&&this->mX <X+20.0f)||(this->mX+40.0f > X&&this->mX+40.0f <X+20.0f)))//size is 40x40
            return true;
        if((this->mY < Y&&this->mY>Y-40.0f) && ((this->mX > X&&this->mX <X+20.0f)||(this->mX+40.0f > X&&this->mX+40.0f <X+20.0f)))//size is 40x40
            return true;
    }

    if (ob->getType()==Objects::Truck){
        if(((this->mY==Y)&&((this->mX > X&&this->mX <X+40.0f)||(this->mX+40.0f > X&&this->mX+40.0f <X+40.0f))))//size is 60x40
            return true;
        if((this->mY > Y&&this->mY<Y+40.0f) && ((this->mX > X&&this->mX <X+40.0f)||(this->mX+40.0f > X&&this->mX+40.0f <X+40.0f)))//size is 60x40
            return true;
        if((this->mY < Y&&this->mY>Y-40.0f) && ((this->mX > X&&this->mX <X+40.0f)||(this->mX+40.0f > X&&this->mX+40.0f <X+40.0f)))//size is 60x40
            return true;
    }
    if (ob->getType()==Objects::Obstacle){
        if(((this->mY==Y)&&((this->mX > X&&this->mX <X+30.0f)||(this->mX+40.0f > X&&this->mX+40.0f <X+30.0f))))//size is 40x40
            return true;
        if((this->mY > Y&&this->mY<Y+40.0f) && ((this->mX > X&&this->mX <X+30.0f)||(this->mX+40.0f > X&&this->mX+40.0f <X+30.0f)))//size is 40x40
            return true;
        if((this->mY < Y&&this->mY>Y-40.0f) && ((this->mX > X&&this->mX <X+30.0f)||(this->mX+40.0f > X&&this->mX+40.0f <X+30.0f)))//size is 40x40
            return true;
    }
    return false;
}

int Player::getPoint() {
    this->point = abs(mY-7*BLOCK_SIZE)/40.0f;
    return this->point;
}

void Player::setX(float x) {
    this->mX = x;
}

void Player::setY(float y) {
    this->mY = y;
}

void Player::setPoint(int p) {
    this->point = p;
}

bool Player::isIdle() {
    return mState->stateID == PlayerStates::Idle;
}

bool Player::isDead() {
    return mState->stateID == PlayerStates::Dead;
}
