#ifndef APPLICATION_H
#define APPLICATION_H

#include "Layer/Layer.h"
#include "LayerStack/LayerStack.h"
#include "Renderer/Renderer.h"

#include <SDL2/SDL.h>

class Application
{
public:
    Application();
    virtual ~Application();

    virtual void pushLayer(Layer *layer);
    virtual void popLayer(Layer *layer);
    virtual void run();
private:
    /* In the future these should be our classes that call SDL */
    SDL_Window *_window;
    /****************/
    Renderer *renderer;

    LayerStack _layer_stack;
    bool _running;
};



#endif /* APPLICATION_H */

