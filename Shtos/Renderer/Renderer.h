#ifndef RENDERER_H
#define RENDERER_H

#include "stdint.h"

#include <SDL2/SDL.h>

class Renderer
{
public:
    static int Initialize(SDL_Window *window, int index, uint32_t flags);
    static void Deinitialize();

    static void SetBlendMode(SDL_BlendMode blendMode);

    static void Clear();
    static void Present();

    static void SetColor(uint8_t r, uint8_t g, uint8_t b, uint8_t a);
    static void FillRect(uint16_t x_pos, uint16_t y_pos, uint16_t width, uint16_t height);
    static void FillRect(const SDL_Rect &rect);
    static void DrawTexture(uint16_t texture_id, uint16_t x_pos, uint16_t y_pos, uint16_t width, uint16_t height);
    static void DrawTexture(uint16_t texture_id, const SDL_Rect &dst_rect);
    static void DrawTexture(uint16_t texture_id, const SDL_Rect &dst_rect, const SDL_Rect &src_rect);

private:
    Renderer();
    ~Renderer();

    static SDL_Renderer *_renderer;
};

#endif /* RENDERER_H */

