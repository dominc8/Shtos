#include "AssetManager/AssetManager.h"
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

void DemoLayer::onUpdate(float elapsed_time, EventHandler *myEventHandler)
{
    //W BUTTON implementation

    if(myEventHandler->KeyPressed(SDL_SCANCODE_W))
    {
        SHTOS_LOG_INFO("Layer 1: W PRESSED");
    }
    if(myEventHandler->KeyReleased(SDL_SCANCODE_W))
    {
        SHTOS_LOG_INFO("Layer 1: W RELEASED");
    }

    Renderer::SetColor(220, 20, 20, 200);
    Renderer::FillRect(100, 100, 300, 200);
    Renderer::SetColor(20, 20, 220, 200);
    Renderer::FillRect(150, 150, 100, 200);
}

