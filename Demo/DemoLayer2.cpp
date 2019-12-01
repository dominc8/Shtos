#include "AssetManager/AssetManager.h"
#include "DemoLayer2.h"
#include "Logger/Logger.h"
#include "Renderer/Renderer.h"

#include <SDL2/SDL.h>

#include <cstdlib>

DemoLayer2::DemoLayer2() : Layer("DemoLayer2") {}

void DemoLayer2::onAttach() {
    _enemy_texture_id = AssetManager::LoadTextureFile("../Demo/assets/saracen.png");
    _enemies.emplace_back(_enemy_texture_id, 50, 60, 100, 100);
    _enemies.emplace_back(_enemy_texture_id, 50, 60, 100, 100);
    _enemies.emplace_back(_enemy_texture_id, 50, 60, 100, 100);
    _enemies.emplace_back(_enemy_texture_id, 50, 60, 100, 100);
    _enemies.emplace_back(_enemy_texture_id, 50, 60, 100, 100);

    _player_texture_id = AssetManager::LoadTextureFile("../Demo/assets/crusader.png");
    _player = new Player(_player_texture_id, 50, 70, 200, 100);
}

void DemoLayer2::onDetach()
{
    delete _player;
}

void DemoLayer2::onUpdate(float elapsed_time)
{
    for (auto &enemy : _enemies)
    {
        enemy.move(elapsed_time * ((std::rand() % 1001) - 500), elapsed_time * ((std::rand() % 1001) - 500));
        enemy.render();
    }

    _player->move(elapsed_time * _player_motion_x, elapsed_time * _player_motion_y);
    _player_motion_x = 0.0f;
    _player_motion_y = 0.0f;
    _player->render();
}

void DemoLayer2::handleEvents(EventHandler *myEventHandler)
{
    static const float scale = 150.0f;

    //W BUTTON implementation
    if(myEventHandler->KeyDown(SDL_SCANCODE_W))
    {
        SHTOS_LOG_INFO("Layer 2: W DOWN");
        _player_motion_y -= scale;
    }

    //S BUTTON implementation
    if(myEventHandler->KeyDown(SDL_SCANCODE_S))
    {
        SHTOS_LOG_INFO("Layer 2: S DOWN");
        _player_motion_y += scale;
    }

    //A BUTTON implementation
    if(myEventHandler->KeyDown(SDL_SCANCODE_A))
    {
        SHTOS_LOG_INFO("Layer 2: A DOWN");
        _player_motion_x -= scale;
    }

    //D BUTTON implementation
    if(myEventHandler->KeyDown(SDL_SCANCODE_D))
    {
        SHTOS_LOG_INFO("Layer 2: D DOWN");
        _player_motion_x += scale;
    }
}

