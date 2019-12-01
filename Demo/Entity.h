#ifndef ENTITY_H
#define ENTITY_H

#include <stdint.h>
#include <cmath>

class Entity
{
public:
    Entity(uint16_t texture_id, uint16_t width, uint16_t height, uint16_t attack_radius, uint16_t health);
    virtual ~Entity();

    float getXPos();
    float getYPos();
    uint16_t getHealth();
    uint16_t getAttackRadius();

    void setHealth(uint16_t inHealth);
    void setXPos(float inX);
    void setYPos(float inY);

    virtual void render();
    virtual void attack(){};
    virtual bool isDead();
    virtual void move(float x_offset, float y_offset);

private:
    float _x_pos;
    float _y_pos;
    uint16_t _health;
    uint16_t _attack_radius;
    uint16_t _width;
    uint16_t _height;
    uint16_t _texture_id;
};

#endif /* ENTITY_H */

