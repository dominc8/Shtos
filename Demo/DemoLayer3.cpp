#include "AssetManager/AssetManager.h"
#include "DemoLayer3.h"
#include "Logger/Logger.h"
#include "Renderer/Renderer.h"

#include <SDL2/SDL.h>

#include <cstdlib>

DemoLayer3::DemoLayer3() : Layer("DemoLayer3") {}

void DemoLayer3::onAttach() {
    _enemy_texture_id = AssetManager::LoadTextureFile("../Demo/assets/ok.png");
    _enemies.emplace_back(_enemy_texture_id, 40, 40);
    _enemies.emplace_back(_enemy_texture_id, 40, 40);
    _enemies.emplace_back(_enemy_texture_id, 40, 40);
    _enemies.emplace_back(_enemy_texture_id, 40, 40);
    _enemies.emplace_back(_enemy_texture_id, 40, 40);

    _player_texture_id = AssetManager::LoadTextureFile("../Demo/assets/czc.jpg");
    _player = new Player(_player_texture_id, 50, 70);
}

void DemoLayer3::onDetach()
{
    delete _player;
}

void DemoLayer3::onUpdate(float elapsed_time, EventHandler *myEventHandler)
{
    static const float scale = 150.0f;

    for (auto &enemy : _enemies)
    {
        enemy.move(elapsed_time * ((std::rand() % 1001) - 500), elapsed_time * ((std::rand() % 1001) - 500));
        enemy.render();
    }

    float player_motion_x = 0;
    float player_motion_y = 0;

    //W BUTTON implementation
    if(myEventHandler->KeyDown(SDL_SCANCODE_W))
    {
        SHTOS_LOG_INFO("Layer 2: W DOWN");
        player_motion_y = -elapsed_time * scale;
    }

    //S BUTTON implementation
    if(myEventHandler->KeyDown(SDL_SCANCODE_S))
    {
        SHTOS_LOG_INFO("Layer 2: S DOWN");
        player_motion_y = elapsed_time * scale;
    }

    //A BUTTON implementation
    if(myEventHandler->KeyDown(SDL_SCANCODE_A))
    {
        SHTOS_LOG_INFO("Layer 2: A DOWN");
        player_motion_x = -elapsed_time * scale;
    }

    //D BUTTON implementation
    if(myEventHandler->KeyDown(SDL_SCANCODE_D))
    {
        SHTOS_LOG_INFO("Layer 2: D DOWN");
        player_motion_x = elapsed_time * scale;
    }

    _player->move(player_motion_x, player_motion_y);
    _player->render();

}

