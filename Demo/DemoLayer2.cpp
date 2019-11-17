#include "AssetManager/AssetManager.h"
#include "DemoLayer2.h"
#include "Logger/Logger.h"
#include "Renderer/Renderer.h"

#include <SDL2/SDL.h>

DemoLayer2::DemoLayer2() : Layer("DemoLayer2") {}

void DemoLayer2::onAttach()
{
    _spain_texture_id = AssetManager::LoadTextureFile("../Demo/assets/love_from_spain.jpg");
    _wpww_texture_id = AssetManager::LoadTextureFile("../Demo/assets/wpww.png");
}

void DemoLayer2::onDetach()
{
}

void DemoLayer2::onUpdate(float elapsed_time)
{
    Renderer::DrawTexture(_wpww_texture_id, 100, 250, 300, 300);
    Renderer::DrawTexture(_spain_texture_id, 500, 0, 300, 300);
    Renderer::DrawTexture(_spain_texture_id, {500, 400, 50, 50});
    Renderer::DrawTexture(_wpww_texture_id, {600, 450, 100, 100}, {200, 200, 300, 300});
}

