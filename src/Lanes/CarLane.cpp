#include "CarLane.h"

CarLane::CarLane(TextureHolder *textures) : Lane(textures) {}

CarLane::~CarLane() {}

void CarLane::drawThis() {
    // DrawRectangle(0, SCREEN_HEIGHT - mY, GetScreenWidth(), 100, LIGHTGRAY);

    Texture2D texture = this->mTextures->get(Textures::Road);
    DrawTexture(texture, (int)pos1.x, (int)pos1.y, WHITE);
    DrawTexture(texture, (int)pos2.x, (int)pos2.y, GRAY);
    DrawTexture(texture, (int)pos3.x, (int)pos3.y, GRAY);
}

void CarLane::updateThis(float dt) {
    addRandomObject(this->type, dt);

    TrafficLampStates::ID state;
    auto objects = getChildren();
    for(auto i = 0 ; i < (int)objects.size(); i++){
        std::shared_ptr<Object> obj = std::dynamic_pointer_cast<Object>(objects[i]);
        if (obj->getType()==Objects::TrafficLamp) {
            state = obj->getLampState();
            break;
        }
    }
    for(auto i = 0 ; i < (int)objects.size(); i++){
        std::shared_ptr<Object> obj = std::dynamic_pointer_cast<Object>(objects[i]);
        switch (state) {
            case TrafficLampStates::ID::Green:
                obj->setSpeed(CAR_SPEED);
                break;
            case TrafficLampStates::ID::Yellow:
                obj->setSpeed(CAR_SPEED/2);
                break;
            case TrafficLampStates::ID::Red:
                obj->setSpeed(0);
                break;
            default:
                break;
        }
    }
}

void CarLane::addObstacles() {}

void CarLane::addTrafficLamp() {
    int randX = GetRandomValue(1, MAP_WIDTH)*BLOCK_SIZE;
    addObject(Objects::TrafficLamp, randX);
}