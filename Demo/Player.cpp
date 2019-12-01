
#include "Player.h"
#include "Logger/Logger.h"

Player::Player(uint16_t texture_id, uint16_t width, uint16_t height, uint16_t attack_radius, uint16_t health) : Entity(texture_id, width,
        height, attack_radius, health)
{
    SHTOS_LOG_INFO("Player constructor");
    this->setYPos(250);
    this->setXPos(250);
    _score = 0;
}

Player::~Player()
{
    SHTOS_LOG_INFO("Player destructor");
}

void Player::attack(Enemy& Enemy)
{
    uint16_t distance =(uint16_t)sqrt(pow(Enemy.getXPos() - this->getXPos(), 2) + pow(Enemy.getYPos() - this->getYPos(), 2));

    if(this->getAttackRadius() >= distance && !Enemy.isDead())
    {
        Enemy.setHealth(Enemy.getHealth() - 20);
        printf("HIT!, enemy hp left:%d\n", Enemy.getHealth());
    }
    else
    {
        printf("Missed!\n");
    }
}

