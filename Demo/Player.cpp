
#include "AssetManager/AssetManager.h"
#include "Player.h"
#include "Renderer/Renderer.h"
#include "Logger/Logger.h"

Player::Player(uint16_t texture_id, uint16_t width, uint16_t height, uint16_t attack_radius, uint16_t health) : Entity(texture_id, width,
        height, attack_radius, health)
{
    SHTOS_LOG_INFO("Player constructor");
    this->setYPos(250);
    this->setXPos(250);
    _score = 0;

    _sword_up_texture_id = AssetManager::LoadTextureFile("assets/sword_up.png");
    _sword_right_texture_id = AssetManager::LoadTextureFile("assets/sword_right.png");
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
        if (Enemy.getHealth() <= 0)
        {
            ++_score;
        }

    }
    else
    {
        printf("Missed!\n");
    }
}

void Player::swordUp()
{
    _sword_attacks = false;
}

void Player::swordRight()
{
    _sword_attacks = true;
}

void Player::render()
{
    Renderer::DrawTexture(_texture_id, _x_pos, _y_pos, _width, _height);
    if (_sword_attacks)
    {
        Renderer::DrawTexture(_sword_right_texture_id, _x_pos + 0.9*_width, _y_pos + 35, 55, 15);
    }
    else
    {
        Renderer::DrawTexture(_sword_up_texture_id, _x_pos + 0.9*_width, _y_pos + 10, 15, 55);
    }
}

int Player::getScore()
{
    return _score;
}


