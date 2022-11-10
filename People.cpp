#include "People.h"

Player::Player(int mX,int mY){
    this->mX = mX;
    this->mY = mY;
    this->mState = false;
}

int Player::getmX(){
    return this->mX;
}
int Player::getmY(){
    return this->mY;
}
//follow by frame
void Player::Up(){
    this->mY++;
}
void Player::Down(){
    this->mY--;
}
void Player::Left(){
    this->mX --;
}
void Player::Right(){
    this->mX++;
}
bool Player::Collision(Object*ob){
    int X = ob->getmX();
    int Y = ob->getmY();

    if(this->mX == X && this->mY == ob->size){
        this->mState = true;
        return true;
    }
    return false;
}   
bool Player::isDead(){
    return this->mState;
}