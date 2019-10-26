#include "Renderer/Renderer.h"
#include "Logger/Logger.h"
#include <SDL2/SDL.h>

SDL_Renderer* Renderer::_renderer = NULL;

int Renderer::Initialize(SDL_Window *window, int index, uint32_t flags)
{
    int ret_value;

    if (NULL == Renderer::_renderer)
    {
        Renderer::_renderer = SDL_CreateRenderer(window, index, flags);
        if (Renderer::_renderer)
        {
            SHTOS_LOG_INFO("Initialized Renderer successfully!");
            ret_value = 1;
        }
        else
        {
            SHTOS_LOG_ERR("Initializing Renderer failed!");
            ret_value = 0;
        }
    }
    else
    {
        ret_value = 2;
    }

    return ret_value;
}

void Renderer::Deinitialize()
{
    SDL_DestroyRenderer(Renderer::_renderer);
    Renderer::_renderer = NULL;
}

void Renderer::SetBlendMode(SDL_BlendMode blendMode)
{
    SDL_SetRenderDrawBlendMode(_renderer, blendMode);
}

void Renderer::Clear()
{
    SDL_RenderClear(Renderer::_renderer);
}

void Renderer::Present()
{
    SDL_RenderPresent(Renderer::_renderer);
}

void Renderer::SetColor(uint8_t r, uint8_t g, uint8_t b, uint8_t a)
{
    SDL_SetRenderDrawColor(Renderer::_renderer, r, g, b, a);
}

void Renderer::FillRect(uint16_t x_pos, uint16_t y_pos, uint16_t width, uint16_t height)
{
    const SDL_Rect rect{x_pos, y_pos, width, height};
    SDL_RenderFillRect(Renderer::_renderer, &rect);
}

