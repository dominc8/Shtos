#ifndef APPLICATION_H
#define APPLICATION_H

#include "Layer/Layer.h"
#include "LayerStack/LayerStack.h"
#include "Renderer/Renderer.h"
#include "EventHandler/EventHandler.h"

#include <SDL2/SDL.h>

class Application
{
public:
    Application();
    virtual ~Application();

    virtual void pushLayer(Layer *layer);
    virtual void popLayer(Layer *layer);
    virtual void run();
protected:
    bool _running;
private:
    SDL_Window *_window;
    Renderer *renderer;

    LayerStack _layer_stack;
    EventHandler* myEventHandler;
};

#endif /* APPLICATION_H */

