#include "DemoLayer.h"
#include "Renderer/Renderer.h"

#include <SDL2/SDL.h>

DemoLayer::DemoLayer() : Layer("DemoLayer") {}

void DemoLayer::onAttach()
{
}

void DemoLayer::onDetach()
{
}

void DemoLayer::onUpdate(float elapsed_time)
{
    Renderer::SetColor(220, 20, 20, 200);
    Renderer::FillRect(100, 100, 300, 200);
    Renderer::SetColor(20, 20, 220, 200);
    Renderer::FillRect(150, 150, 100, 200);
}

