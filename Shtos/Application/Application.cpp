#include "Application/Application.h"
#include "Logger/Logger.h"

#include <SDL2/SDL.h>

#include <chrono>
#include "assert.h"

Application::Application()
{
    SHTOS_LOG_INFO("Application constructor\n");
    _running = true;
    if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
    {
        SHTOS_LOG_INFO("SDL_Init is good\n");
        _window = SDL_CreateWindow("Window", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, 0);
        if (_window)
        {
            SHTOS_LOG_INFO("Window is good\n"); 
            _renderer = SDL_CreateRenderer(_window, -1, 0);

            if (_renderer)
            {
                SHTOS_LOG_INFO("Renderer is good\n");
            }
            else
            {
                SHTOS_LOG_ERR("Couldn't create renderer\n");
                _running = false;
            }
        }
        else
        {
            SHTOS_LOG_ERR("Couldn't create window!\n");
            _running = false;
        }
    }
    else
    {
        SHTOS_LOG_ERR("Couldn't initialize SDL\n");
        _running = false;
    }
    assert(_running);
}

Application::~Application()
{
    SHTOS_LOG_INFO("Application destructor\n");
    SDL_DestroyRenderer(_renderer);
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

void Application::Run()
{
    float current_time, elapsed_time;
    while (_running)
    {
        current_time = std::chrono::system_clock::now();
        elapsed_time = std::chrono::duration<float>(current_time - _last_time).count();
        _last_time = current_time;

        /* Handling events here (loop through all stored events in a queue for every layer)
         * or in loop below (call layer->handleEvents() or sth like that and there layer will decide which events it is interested in */

        for (Layer *layer : _layer_stack)
        {
            layer->onUpdate(elapsed_time);
        }
    }
}
