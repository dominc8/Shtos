#include "AssetManager/AssetManager.h"
#include "Logger/Logger.h"
#include "Renderer/Renderer.h"

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

SDL_Renderer* Renderer::_renderer = NULL;

int Renderer::Initialize(SDL_Window *window, int index, uint32_t flags)
{
    int ret_value;

    if (NULL == _renderer)
    {
        _renderer = SDL_CreateRenderer(window, index, flags);
        if (_renderer)
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
    SDL_DestroyRenderer(_renderer);
    _renderer = NULL;
}

void Renderer::SetBlendMode(SDL_BlendMode blendMode)
{
    SDL_SetRenderDrawBlendMode(_renderer, blendMode);
}

void Renderer::Clear()
{
    SDL_RenderClear(_renderer);
}

void Renderer::Present()
{
    SDL_RenderPresent(_renderer);
}

void Renderer::SetColor(uint8_t r, uint8_t g, uint8_t b, uint8_t a)
{
    SDL_SetRenderDrawColor(_renderer, r, g, b, a);
}

void Renderer::FillRect(uint16_t x_pos, uint16_t y_pos, uint16_t width, uint16_t height)
{
    const SDL_Rect rect{x_pos, y_pos, width, height};
    SDL_RenderFillRect(_renderer, &rect);
}

void Renderer::FillRect(const SDL_Rect &rect)
{
    SDL_RenderFillRect(_renderer, &rect);
}

void Renderer::DrawTexture(uint16_t texture_id, uint16_t x_pos, uint16_t y_pos, uint16_t width, uint16_t height)
{
    uint16_t ret_id = AssetManager::LoadTexture(_renderer, texture_id);
    if (ret_id != texture_id)
    {
        SHTOS_LOG_ERR("AssetManager::LoadTexture didn't return correct id!\n");
    }
    else
    {
        SDL_Texture *texture = AssetManager::GetTexture(texture_id);
        const SDL_Rect dst_rect{x_pos, y_pos, width, height};
        int error_value = SDL_RenderCopy(_renderer, texture, NULL, &dst_rect);
        if (error_value)
        {
            SHTOS_LOG_ERR("SDL_RenderCopy returned %d: %s\n!", error_value, SDL_GetError());
        }
    }
}

void Renderer::DrawTexture(uint16_t texture_id, const SDL_Rect &dst_rect)
{
    uint16_t ret_id = AssetManager::LoadTexture(_renderer, texture_id);
    if (ret_id != texture_id)
    {
        SHTOS_LOG_ERR("AssetManager::LoadTexture didn't return correct id!\n");
    }
    else
    {
        SDL_Texture *texture = AssetManager::GetTexture(texture_id);
        int error_value = SDL_RenderCopy(_renderer, texture, NULL, &dst_rect);
        if (error_value)
        {
            SHTOS_LOG_ERR("SDL_RenderCopy returned %d: %s\n!", error_value, SDL_GetError());
        }
    }
}

void Renderer::DrawTexture(uint16_t texture_id, const SDL_Rect &dst_rect, const SDL_Rect &src_rect)
{
    uint16_t ret_id = AssetManager::LoadTexture(_renderer, texture_id);
    if (ret_id != texture_id)
    {
        SHTOS_LOG_ERR("AssetManager::LoadTexture didn't return correct id!\n");
    }
    else
    {
        SDL_Texture *texture = AssetManager::GetTexture(texture_id);
        int error_value = SDL_RenderCopy(_renderer, texture, &src_rect, &dst_rect);
        if (error_value)
        {
            SHTOS_LOG_ERR("SDL_RenderCopy returned %d: %s\n!", error_value, SDL_GetError());
        }
    }
}

