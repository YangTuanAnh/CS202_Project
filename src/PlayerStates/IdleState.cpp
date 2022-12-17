#include "IdleState.h"
#include "../Player.hpp"

#include <raylib.h>

IdleState::IdleState(Player& player) : PlayerState(player, PlayerStates::Idle) {}

void IdleState::update(float dt) {
    int keyPressed = GetKeyPressed();
    if (keyPressed == KEY_W || keyPressed == KEY_A || keyPressed == KEY_S || keyPressed == KEY_D) {
        Directions::ID direction;
        player.setState(PlayerStates::Jumping);
        switch (keyPressed) {
        case KEY_W:
            direction = Directions::Up;
            break;
        case KEY_S:
            direction = Directions::Down;
            break;
        case KEY_A:
            direction = Directions::Left;
            break;
        case KEY_D:
            direction = Directions::Right;
            break;
        default:
            break;
        }
        player.mState->setTarget(Vector2{player.getX(), player.getY()}, direction);
    }
}