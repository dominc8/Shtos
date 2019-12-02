#ifndef ENEMY_H
#define ENEMY_H

#include "Entity.h"

class Enemy : public Entity
{
public:
    Enemy(uint16_t texture_id, uint16_t width, uint16_t height, uint16_t attack_radius, uint16_t health, float x, float y);
    virtual ~Enemy();
    void virtual attack(Entity* Player);
};

#endif /* PLAYER_H */
