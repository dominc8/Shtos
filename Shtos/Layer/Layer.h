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
    virtual void onUpdate(float elapsed_time) {}
    virtual void handleEvents(EventHandler *myEventHandler){}

    const char* getName() { return _name; }

protected:
    const char* _name;
};

#endif /* LAYER_H */

