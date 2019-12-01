#ifndef DEMOLAYER2_H
#define DEMOLAYER2_H

#include "Layer/Layer.h"
#include "Logger/Logger.h"
#include "EventHandler/EventHandler.h"
#include "Entity.h"
#include "Player.h"
#include "Enemy.h"

#include <stdint.h>
#include <vector>

class DemoLayer2 : public Layer
{
public:
    DemoLayer2();
    virtual ~DemoLayer2() = default;

    virtual void onAttach();
    virtual void onDetach();
    virtual void onUpdate(float elapsed_time);
    virtual void handleEvents(EventHandler *myEventHandler);
private:
    uint16_t _enemy_texture_id;
    std::vector<Enemy> _enemies;

    uint16_t _player_texture_id;
    float _player_motion_x = 0.0f;
    float _player_motion_y = 0.0f;
    Player *_player;
};

#endif /* DEMOLAYER2_H */

