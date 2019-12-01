#include "Entity.h"
#include "Renderer/Renderer.h"
#include "Logger/Logger.h"

Entity::Entity(uint16_t texture_id, uint16_t width, uint16_t height, uint16_t attack_radius, uint16_t health) : _texture_id(texture_id), _width(width), _height(height),
    _attack_radius(attack_radius), _health(health)
{
    SHTOS_LOG_INFO("Creating Entity with texture_id: %d", texture_id);
};

Entity::~Entity()
{
    SHTOS_LOG_INFO("Destroying Entity with texture_id: %d", _texture_id);
};

void Entity::render()
{
    Renderer::DrawTexture(_texture_id, _x_pos, _y_pos, _width, _height);
}

void Entity::move(float x_offset, float y_offset)
{
    _x_pos += x_offset;
    _y_pos += y_offset;

    if (_x_pos < 0) _x_pos = 0;
    if (_x_pos > 800 - _width) _x_pos = 800 - _width;

    if (_y_pos < 0) _y_pos = 0;
    if (_y_pos > 600 - _height) _y_pos = 600 - _height;
}

bool Entity::isDead()
{
    if( _health <= 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

uint16_t Entity::getAttackRadius()
{
    return _attack_radius;
}

uint16_t Entity::getHealth()
{
    return _health;
}

float Entity::getXPos()
{
    return _x_pos;
}

float Entity::getYPos()
{
    return _y_pos;
}

void Entity::setHealth(uint16_t inHealth)
{
    _health = inHealth;
}

void Entity::setXPos(float inX)
{
    _x_pos = inX;
}

void Entity::setYPos(float inY)
{
    _y_pos = inY;
}