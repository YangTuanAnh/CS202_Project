#include "IdleState.h"
#include "../Player.hpp"

#include <raylib.h>

IdleState::IdleState(Player& player) : PlayerState(player, PlayerStates::Idle) {}

void IdleState::update(float dt) {
    Directions::ID direction;
    if (IsKeyPressed(KEY_W)) {
        player.setState(PlayerStates::Jumping);
        direction = Directions::Up;
        player.mState->setTarget(Vector2{player.getX(), player.getY()}, direction);
    } else if (IsKeyPressed(KEY_S)) {
        player.setState(PlayerStates::Jumping);
        direction = Directions::Down;
        player.mState->setTarget(Vector2{player.getX(), player.getY()}, direction);
    } else if (IsKeyPressed(KEY_A)) {
        player.setState(PlayerStates::Jumping);
        direction = Directions::Left;
        player.mState->setTarget(Vector2{player.getX(), player.getY()}, direction);
    } else if (IsKeyPressed(KEY_D)) {
        player.setState(PlayerStates::Jumping);
        direction = Directions::Right;
        player.mState->setTarget(Vector2{player.getX(), player.getY()}, direction);
    }
}