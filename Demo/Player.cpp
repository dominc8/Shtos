
#include "Player.h"
#include "Logger/Logger.h"

Player::Player(uint16_t texture_id, uint16_t width, uint16_t height) : Entity(texture_id, width, height)
{
    SHTOS_LOG_INFO("Player constructor");
}

Player::~Player()
{
    SHTOS_LOG_INFO("Player destructor");
}

