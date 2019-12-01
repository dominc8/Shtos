#ifndef DEMOLAYER3_H
#define DEMOLAYER3_H

#include "Layer/Layer.h"
#include "Logger/Logger.h"
#include "EventHandler/EventHandler.h"
#include "Entity.h"
#include "Player.h"

#include <stdint.h>
#include <vector>

class DemoLayer3 : public Layer
{
public:
    DemoLayer3();
    virtual ~DemoLayer3() = default;

    virtual void onAttach();
    virtual void onDetach();
    virtual void onUpdate(float elapsed_time, EventHandler *myEventHandler);
private:
    uint16_t _enemy_texture_id;
    uint16_t _player_texture_id;
    std::vector<Entity> _enemies;
    Player *_player;
};

#endif /* DEMOLAYER3_H */

