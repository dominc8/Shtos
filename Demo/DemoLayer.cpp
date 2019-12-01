#include "AssetManager/AssetManager.h"
#include "DemoLayer.h"
#include "Renderer/Renderer.h"
#include "Logger/Logger.h"


#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>

DemoLayer::DemoLayer() : Layer("DemoLayer") {}

void DemoLayer::onAttach()
{
    _bg_texture_id = AssetManager::LoadTextureFile("../Demo/assets/bg.jpg");

    _bg_music_id = AssetManager::LoadMusic("../Demo/assets/the-chant.mp3");
    AssetManager::PlayMusic(_bg_music_id);
}

void DemoLayer::onDetach()
{
}

void DemoLayer::onUpdate(float elapsed_time)
{
    Renderer::DrawTexture(_bg_texture_id, 0, 0, 800, 600);
}
void DemoLayer::handleEvents(EventHandler *myEventHandler)
{
}

