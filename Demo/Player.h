#ifndef PLAYER_H
#define PLAYER_H

#include "Entity.h"
#include "Enemy.h"

class Player : public Entity
{
public:
    Player(uint16_t texture_id, uint16_t width, uint16_t height, uint16_t attack_radius, uint16_t health);
    virtual ~Player();
    virtual void attack(Enemy& Enemy);

private:
    int _score;

};

#endif /* PLAYER_H */

