#include "stdio.h"

#include <SDL2/SDL.h>

#include "Logger/Logger.h"

class Game
{
public:
    Game() {};
    ~Game() {};

    void init(const char *title, int x_pos, int y_pos, int width, int height, bool fullscreen)
    {
        int flags = fullscreen ? SDL_WINDOW_FULLSCREEN : 0;

        int init_counter = 0;

        _is_running = false;

        if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
        {
            ++init_counter;
            SHTOS_LOG_INFO("SDL_Init is good\n");

            _window = SDL_CreateWindow(title, x_pos, y_pos, width, height, flags);
            if (_window)
            {
                ++init_counter;
                SHTOS_LOG_INFO("Window is good\n");

            }

            _renderer = SDL_CreateRenderer(_window, -1, 0);
            if (_renderer)
            {
                ++init_counter;
                SDL_SetRenderDrawColor(_renderer, 20, 220, 20, 200);
                SHTOS_LOG_INFO("Renderer is good\n");
            }
        }

        if (init_counter == 3)
        {
            _is_running = true;
        }
    }

    void handleEvents()
    {
        SDL_Event event;
        SDL_PollEvent(&event);
        switch (event.type)
        {
            case SDL_QUIT:
                _is_running = false;
                break;
            default:
                break;
        }

    }

    void update()
    {

    }

    void render()
    {
        SDL_RenderClear(_renderer);
        SDL_RenderPresent(_renderer);

    }

    void clean()
    {
        SDL_DestroyRenderer(_renderer);
        SDL_DestroyWindow(_window);
        SDL_Quit();
        SHTOS_LOG_INFO("Cleaned\n");
    }

    bool isRunning()
    { 
        return _is_running;
    }

private:
    bool _is_running;
    SDL_Window *_window;
    SDL_Renderer *_renderer;
};








int main(int argc, char *argv[])
{

    Game game;
    game.init("Game title!", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, false);

    while (game.isRunning())
    {
        game.handleEvents();
        game.update();
        game.render();
    }

    game.clean();

    SHTOS_LOG_INFO("Info test\n");
    SHTOS_LOG_WARN("Warning test\n");
    SHTOS_LOG_ERR("Error test\n");

    return 0;
}
