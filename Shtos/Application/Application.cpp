#include "Application/Application.h"
#include "Logger/Logger.h"

#include <SDL2/SDL.h>

#include <chrono>
#include "assert.h"

Application::Application()
{
    SHTOS_LOG_INFO("Application constructor");
    _running = true;
    if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
    {
        SHTOS_LOG_INFO("SDL_Init is good");
        _window = SDL_CreateWindow("Window", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, 0);
        if (_window)
        {
            SHTOS_LOG_INFO("Window is good"); 
            
            if (Renderer::Initialize(_window, -1, 0))
            {
                SHTOS_LOG_INFO("Renderer is good");
                Renderer::SetBlendMode(SDL_BLENDMODE_BLEND);
            }
            else
            {
                SHTOS_LOG_ERR("Couldn't create renderer");
                _running = false;
            }
        }
        else
        {
            SHTOS_LOG_ERR("Couldn't create window!");
            _running = false;
        }
    }
    else
    {
        SHTOS_LOG_ERR("Couldn't initialize SDL");
        _running = false;
    }
    assert(_running);
}

Application::~Application()
{
    SHTOS_LOG_INFO("Application destructor");
    Renderer::Deinitialize();
    SDL_DestroyWindow(_window);
    SDL_Quit();
}

void Application::pushLayer(Layer *layer)
{
    _layer_stack.pushLayer(layer);
}

void Application::popLayer(Layer *layer)
{
    _layer_stack.popLayer(layer);
}

void Application::run()
{
    std::chrono::system_clock::time_point last_time, current_time;
    last_time = std::chrono::system_clock::now();
    float elapsed_time;
    while (_running)
    {
        current_time = std::chrono::system_clock::now();
        elapsed_time = std::chrono::duration<float>(current_time - last_time).count();
        last_time = current_time;

        SDL_Event event;
        SDL_PollEvent(&event);
        switch (event.type)
        {
        case SDL_QUIT:
                _running = false;
                break;
            default:
                break;
        }

        /* Handling events here (loop through all stored events in a queue for every layer)
         * or in loop below (call layer->handleEvents() or sth like that and there layer will decide which events it is interested in */
        Renderer::SetColor(0, 0, 0, 255);
        Renderer::Clear();

        for (Layer *layer : _layer_stack)
        {
            layer->onUpdate(elapsed_time);
        }

        Renderer::Present();
    }
}