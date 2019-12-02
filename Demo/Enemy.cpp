
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

void Enemy::attack(Entity *Player, float elapsed_time)
{
    uint16_t distance =(uint16_t)sqrt(pow(Player->getXPos() - this->getXPos(), 2) + pow(Player->getYPos() - this->getYPos(), 2));

    if(this->getAttackRadius() >= distance)
    {
        Player->setHealth(Player->getHealth() - 0.002f * elapsed_time);
    }
}
