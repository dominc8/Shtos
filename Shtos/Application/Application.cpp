#include "Application/Application.h"
#include "AssetManager/AssetManager.h"
#include "Logger/Logger.h"
#include "EventHandler/EventHandler.h"

#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>

#include <assert.h>
#include <chrono>

Application::Application() : _frame_count(0)
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
            
            if (Renderer::Initialize(_window, -1, SDL_RENDERER_PRESENTVSYNC))
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

        if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
        {
            SHTOS_LOG_ERR("Mix_OpenAudio failed: %s!", SDL_GetError());
        }
    }
    else
    {
        SHTOS_LOG_ERR("Couldn't initialize SDL");
        _running = false;
    }
    AssetManager::Initialize();
    assert(_running);
}

Application::~Application()
{
    SHTOS_LOG_INFO("Application destructor");
    AssetManager::Deinitialize();
    Mix_Quit();
    Renderer::Deinitialize();

    EventHandler::Release();
    myEventHandler = NULL;

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
    std::chrono::system_clock::time_point begin_application = std::chrono::system_clock::now();
    std::chrono::system_clock::time_point last_time, current_time;
    last_time = std::chrono::system_clock::now();

    myEventHandler = EventHandler::Instance();

    float elapsed_time;
    while (_running)
    {
        ++_frame_count;
        current_time = std::chrono::system_clock::now();
        elapsed_time = std::chrono::duration<float>(current_time - last_time).count();
        last_time = current_time;

        myEventHandler->Update();

        SDL_Event event;
        while(SDL_PollEvent(&event) != 0)
        {
            if(event.type == SDL_QUIT)
            {
                _running = false;
            }
        }

        Renderer::SetColor(0, 0, 0, 255);
        Renderer::Clear();
        myEventHandler->Update();

        for (auto iter = _layer_stack.rbegin(); iter != _layer_stack.rend(); ++iter)
        {
            (*iter)->handleEvents(myEventHandler);
        }

        for (Layer *layer : _layer_stack)
        {
            layer->onUpdate(elapsed_time);
        }

        myEventHandler->UpdatePrevInput();
        Renderer::Present();
    }

    std::chrono::system_clock::time_point end_application = std::chrono::system_clock::now();
    float app_time = std::chrono::duration<float>(end_application - begin_application).count();
    SHTOS_LOG_INFO("Application::Run ends, recorded %d frames during %f seconds, on average there were %f FPS", _frame_count, app_time, ((float)_frame_count/app_time));

}

