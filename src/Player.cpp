#include "Player.h"

#define PLAYER_BASE_SIZE    40.0f
#define PLAYER_SPEED        40.0f
Player::Player(float mX,float mY,int Point){
    this->mX = mX;
    this->mY = mY;
    this->mState = false;
    this->point = Point;
}

void Player::init(Texture2D* texture) {
    chicken = texture;
}

void Player::movement(){
    string in;
	in =_getch();
	if (in == "w") {
		this->mY++;
		this->point++;
	}
	if (in == "s") {
		this->mY--;
	}
	if (in == "a") {
		this->mX--;
	}
	if (in == "d") {
		this->mX++;
	}
}
float Player::getmX(){
    return this->mX;
}
float Player::getmY(){
    return this->mY;
}
void Player::draw(){
    // BeginDrawing();
        // ClearBackground(RAYWHITE);
        if(!this->isDead()){
            int frameWidth = chicken->width;
            int frameHeight = chicken->height;
            Rectangle source = {0.0f,0.0f, (float) frameWidth,(float) frameHeight};
            Vector2 position;
            position.x = this->mX;
            position.y = this->mY;
            DrawTextureRec(*chicken,source,position,RED);
            //DrawRectangle(this->mX,this->mY,PLAYER_BASE_SIZE,PLAYER_BASE_SIZE,RED);
        }
    // EndDrawing();
}
void Player::update(){
    if(!this->isDead()){
        if(IsKeyPressed('S')){
            this->mY+=PLAYER_SPEED;
        }
        if(IsKeyPressed('W')){
            this->mY-=PLAYER_SPEED;
        }
        if(IsKeyPressed('D')){
            this->mX+=PLAYER_SPEED;
        }
        if(IsKeyPressed('A')){
            this->mX-=PLAYER_SPEED;
        }
        if (this->mX < 0) this->mX = 0;
        else if ((this->mX + PLAYER_BASE_SIZE) > WIDTH) this->mX = WIDTH - PLAYER_BASE_SIZE;
        if (this->mY < 0) this->mY = 0;
        else if ((this->mY + PLAYER_BASE_SIZE+30) > HEIGHT) this->mY = HEIGHT - PLAYER_BASE_SIZE-30;

    }
}
bool Player::collision(Object*ob){
    float X = ob->getX();
    float Y = ob->getY();

    if(this->mX == X && this->mY == Y && this->mX == (ob->type()%2+1)){
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
void Player::setX(float x){
    this->mX = x;
}
void Player::setY(float y){
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