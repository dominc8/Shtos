#include "AssetManager/AssetManager.h"
#include "DemoLayer2.h"
#include "Logger/Logger.h"
#include "Renderer/Renderer.h"

#include <SDL2/SDL.h>

DemoLayer2::DemoLayer2() : Layer("DemoLayer2") {}

void DemoLayer2::onAttach() {
    _spain_texture_id = AssetManager::LoadTextureFile("../Demo/assets/love_from_spain.jpg");
    _wpww_texture_id = AssetManager::LoadTextureFile("../Demo/assets/wpww.png");
    _czc_texture_id = AssetManager::LoadTextureFile("../Demo/assets/czc.jpg");
    _ok_texture_id = AssetManager::LoadTextureFile("../Demo/assets/ok.png");
}

void DemoLayer2::onDetach()
{
}

void DemoLayer2::onUpdate(float elapsed_time)
{
//     Renderer::DrawTexture(_wpww_texture_id, 100, 250, 300, 300);
//     Renderer::DrawTexture(_spain_texture_id, 500, 0, 300, 300);
//     Renderer::DrawTexture(_spain_texture_id, {500, 400, 50, 50});
//     Renderer::DrawTexture(_wpww_texture_id, {600, 450, 100, 100}, {200, 200, 300, 300});
    Renderer::DrawTexture(_czc_texture_id, _x_czc, _y_czc, 79, 118);
    Renderer::DrawTexture(_ok_texture_id, 50, 100, 150, 150);
}
void DemoLayer2::handleEvents(EventHandler *myEventHandler)
{
    //W BUTTON implementation
    if(myEventHandler->KeyPressed(SDL_SCANCODE_W))
    {
        SHTOS_LOG_INFO("Layer 2: W PRESSED");
        _y_czc = _y_czc < 20 ? 0 : _y_czc - 20;
    }
    if(myEventHandler->KeyReleased(SDL_SCANCODE_W))
    {
        SHTOS_LOG_INFO("Layer 2: W RELEASED");
    }

    //S BUTTON implementation

    if(myEventHandler->KeyPressed(SDL_SCANCODE_S))
    {
        SHTOS_LOG_INFO("Layer 2: S PRESSED");
        _y_czc = _y_czc > 580 ? 600 : _y_czc + 20;
    }
    if(myEventHandler->KeyReleased(SDL_SCANCODE_S))
    {
        SHTOS_LOG_INFO("Layer 2: S RELEASED");
    }

    //A BUTTON implementation
    if(myEventHandler->KeyPressed(SDL_SCANCODE_A))
    {
        SHTOS_LOG_INFO("Layer 2: A PRESSED");
        _x_czc = _x_czc < 20 ? 0 : _x_czc - 20;
    }
    if(myEventHandler->KeyReleased(SDL_SCANCODE_A))
    {
        SHTOS_LOG_INFO("Layer 2: A RELEASED");
    }

    //D BUTTON implementation
    if(myEventHandler->KeyPressed(SDL_SCANCODE_D))
    {
        SHTOS_LOG_INFO("Layer 2: D PRESSED");
        _x_czc = _x_czc > 780 ? 800 : _x_czc + 20;
    }
    if(myEventHandler->KeyReleased(SDL_SCANCODE_D))
    {
        SHTOS_LOG_INFO("Layer 2: D RELEASED");
    }
}
