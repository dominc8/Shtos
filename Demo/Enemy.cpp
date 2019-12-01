
#include "Enemy.h"
#include "Logger/Logger.h"

Enemy::Enemy(uint16_t texture_id, uint16_t width, uint16_t height, uint16_t attack_radius, uint16_t health) :
        Entity(texture_id, width, height, attack_radius, health)
{
    SHTOS_LOG_INFO("Enemy constructor");
}

Enemy::~Enemy()
{
    SHTOS_LOG_INFO("Enemy destructor");
}

void Enemy::attack(Entity *Player)
{

}