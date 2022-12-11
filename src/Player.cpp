#include "Player.h"

Player::Player(int mX,int mY,int Point){
    this->mX = mX;
    this->mY = mY;
    this->mState = false;
    this->point = Point;
}
void Player::movement(){
    string in;
	in =_getch();
	if (in == "w") {
		this->Y++;
		this->score++;
	}
	if (in == "s") {
		this->Y--;
	}
	if (in == "a") {
		this->X--;
	}
	if (in == "d") {
		this->X++;
	}
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
    this->point++;
    
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

    if(this->mX == X && this->mY == Y && this->mX == (ob->getsize()-1)){
        this->mState = true;
        return true;
    }
    return false;
}   
bool Player::isDead(){
    return this->mState;
}
int Player::getPoint(){
    return this->point;
}
void Player::setX(int x){
    this->mX = x;
}
void Player::setY(int y){
    this->mY  =y;
}
void Player::setPoint(int p){
    this->point = p;
}
Player::~Player(){
    this->mState = true;
    this->mX = 0;
    this->mY = 0;
    this->point = 0;
}