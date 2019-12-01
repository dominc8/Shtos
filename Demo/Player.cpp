
#include "Player.h"
#include "Logger/Logger.h"

Player::Player(uint16_t texture_id, uint16_t width, uint16_t height, uint16_t attack_radius, uint16_t health) : Entity(texture_id, width,
        height, attack_radius, health)
{
    SHTOS_LOG_INFO("Player constructor");
    _score = 0;
}

Player::~Player()
{
    SHTOS_LOG_INFO("Player destructor");
}

void Player::attack()
{

}

