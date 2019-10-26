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

private:
    Renderer();
    ~Renderer();

    static SDL_Renderer *_renderer;
};

#endif /* RENDERER_H */

