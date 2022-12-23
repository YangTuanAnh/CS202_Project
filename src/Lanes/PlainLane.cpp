#include "PlainLane.h"

PlainLane::PlainLane(TextureHolder *textures) : Lane(textures) {}

PlainLane::~PlainLane() {}

// void PlainLane::update(float dt) {
//     std::cerr << "Update lane" << std::endl;
//     int i = 0;
//     for (auto &object : objects) {
//         std::cerr << ++i << std::endl;
//         object->update(dt);
//     }
// }

// void PlainLane::draw() {
//     std::cerr << "Draw lane" << std::endl;
//     DrawRectangle(0, SCREEN_HEIGHT - mY, GetScreenWidth(), 100, GREEN);
//     int i = 0;
//     for (auto &object : objects) {
//         std::cerr << ++i << std::endl;
//         object->draw();
//     }
// }