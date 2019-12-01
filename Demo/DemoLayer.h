#ifndef DEMOLAYER_H
#define DEMOLAYER_H

#include "Layer/Layer.h"
#include "EventHandler/EventHandler.h"
#include "Logger/Logger.h"

#include <SDL2/SDL_mixer.h>

class DemoLayer : public Layer
{
public:
    DemoLayer();
    virtual ~DemoLayer() = default;

    virtual void onAttach();
    virtual void onDetach();
    virtual void onUpdate(float elapsed_time);
    virtual void handleEvents(EventHandler *myEventHandler);
private:
    uint16_t _bg_texture_id;
    uint16_t _bg_music_id;
};

#endif /* DEMOLAYER_H */

