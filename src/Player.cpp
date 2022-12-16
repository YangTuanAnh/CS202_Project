#include "Player.hpp"

#include <cassert>
#include <iostream>

#define PLAYER_BASE_SIZE 40.0f
#define PLAYER_SPEED 40.0f

Player::Player() {
    std::cerr << "Player constructor" << std::endl;
    this->mX = 0.0f;
    this->mY = 0.0f;
    this->point = 0;
}

Player::Player(float mX, float mY, int Point) {
    std::cerr << "Player constructor" << std::endl;
    this->mX = mX;
    this->mY = mY;
    this->point = Point;
}

void Player::init(Texture2D *texture) {
    chicken = texture;
    mState = createState(PlayerStates::Idle);
}

PlayerState::Ptr Player::createState(PlayerStates::ID stateID) {
    auto found = mFactories.find(stateID);
    assert(found != mFactories.end());
    return found->second();
}

void Player::movement() {
    string in;
    in = _getch();
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

float Player::getX() {
    return this->mX;
}

float Player::getY() {
    return this->mY;
}

void Player::setState(PlayerStates::ID id) {
    mState = createState(id);
}

void Player::draw() {
    // ClearBackground(RAYWHITE);
    if (!this->isDead()) {
        int frameWidth = chicken->width;
        int frameHeight = chicken->height;
        Rectangle source = {0.0f, 0.0f, (float)frameWidth, (float)frameHeight};
        Vector2 position{this->mX, this->mY};
        switch (this->mState->stateID) {
        case PlayerStates::Idle:
            DrawTextureRec(*chicken, source, position, RED);
            break;
        case PlayerStates::Jumping:
            DrawTextureRec(*chicken, source, position, WHITE);
            break;
        default:
            break;
        }
        
        // DrawRectangle(this->mX,this->mY,PLAYER_BASE_SIZE,PLAYER_BASE_SIZE,RED);
    }
}

void Player::update(float dt) {
    // if (!this->isDead()) {
    //     if (IsKeyPressed('S'))
    //     {
    //         this->mY += PLAYER_SPEED;
    //     }
    //     if (IsKeyPressed('W'))
    //     {
    //         this->mY -= PLAYER_SPEED;
    //     }
    //     if (IsKeyPressed('D'))
    //     {
    //         this->mX += PLAYER_SPEED;
    //     }
    //     if (IsKeyPressed('A'))
    //     {
    //         this->mX -= PLAYER_SPEED;
    //     }
    //     if (this->mX < 0)
    //         this->mX = 0;
    //     else if ((this->mX + PLAYER_BASE_SIZE) > WIDTH)
    //         this->mX = WIDTH - PLAYER_BASE_SIZE;
    //     if (this->mY < 0)
    //         this->mY = 0;
    //     else if ((this->mY + PLAYER_BASE_SIZE + 30) > HEIGHT)
    //         this->mY = HEIGHT - PLAYER_BASE_SIZE - 30;
    // }
    mState->update(dt);
}

bool Player::collision(Object *ob) {
    float X = ob->getX();
    float Y = ob->getY();

    if (this->mX == X && this->mY == Y && this->mX == (ob->type() % 2 + 1)) {
        return true;
    }
    return false;
}

int Player::getPoint() {
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

bool Player::isDead() {
    return mState->stateID == PlayerStates::Dead;
}

Player::~Player() {
    this->mX = 0;
    this->mY = 0;
    this->point = 0;
}