#ifndef LAYER_H
#define LAYER_H

#include "EventHandler/EventHandler.h"

class Layer
{
public:
    Layer(const char *name = "Layer");
    virtual ~Layer() = default;

    virtual void onAttach() {}
    virtual void onDetach() {}
    virtual void onUpdate(float elapsed_time, EventHandler *myEventHandler) {}
    // TODO: After adding Event management virtual void onEvent(Event& event) {}
    //       or handleEvents() or whatever
    virtual void handleEvents(){}

    const char* getName() { return _name; }

protected:
    const char* _name;
};

#endif /* LAYER_H */

