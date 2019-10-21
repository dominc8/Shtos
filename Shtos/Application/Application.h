#ifndef APPLICATION_H
#define APPLICATION_H

#include "Layer/Layer.h"
#include "LayerStack/LayerStack.h"

#include <SDL2/SDL.h>

class Application
{
public:
    Application();
    ~Application();

    void pushLayer(Layer *layer);
    void popLayer(Layer *layer);
    void Run();
private:
    /* In the future these should be our classes that call SDL */
    SDL_Window *_window;
    SDL_Renderer *_renderer;
    /****************/

    LayerStack _layer_stack;
    bool _running;
    float _last_time = 0.0f;
};



#endif /* APPLICATION_H */

