#ifndef DEMOLAYER_H
#define DEMOLAYER_H

#include "Layer/Layer.h"
#include "EventHandler/EventHandler.h"
#include "Logger/Logger.h"

class DemoLayer : public Layer
{
public:
    DemoLayer();
    virtual ~DemoLayer() = default;

    virtual void onAttach();
    virtual void onDetach();
    virtual void onUpdate(float elapsed_time);
    virtual void handleEvents(EventHandler *myEventHandler);
};

#endif /* DEMOLAYER_H */

