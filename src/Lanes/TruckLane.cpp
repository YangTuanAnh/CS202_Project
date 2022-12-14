#include "TruckLane.h"

TruckLane::TruckLane(TextureHolder *textures) : Lane(textures, Lanes::Truck, Objects::Truck) {}

TruckLane::~TruckLane() {}

void TruckLane::drawThis() {
    // DrawRectangle(0, SCREEN_HEIGHT - mY, GetScreenWidth(), 100, LIGHTGRAY);

    Texture2D texture = this->mTextures->get(Textures::Road);
    DrawTexture(texture, (int)pos1.x, (int)pos1.y, WHITE);
    DrawTexture(texture, (int)pos2.x, (int)pos2.y, GRAY);
    DrawTexture(texture, (int)pos3.x, (int)pos3.y, GRAY);
}

void TruckLane::updateThis(float dt) {
    addRandomObject(this->type, dt);
    removeOutOfView();

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

void TruckLane::addObstacles() {}

void TruckLane::addTrafficLamp() {
    int randX = GetRandomValue(0, MAP_WIDTH-1)*BLOCK_SIZE;
    addObject(Objects::TrafficLamp, randX);
}