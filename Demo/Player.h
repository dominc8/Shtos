#ifndef PLAYER_H
#define PLAYER_H

#include "Entity.h"

class Player : public Entity
{
public:
    Player(uint16_t texture_id, uint16_t width, uint16_t height);
    virtual ~Player();
};

#endif /* PLAYER_H */

