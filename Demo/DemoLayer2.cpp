#include "AssetManager/AssetManager.h"
#include "DemoLayer2.h"
#include "Logger/Logger.h"
#include "Renderer/Renderer.h"

#include <SDL2/SDL.h>

#include <cstdlib>

bool _was_attack = false;
float _time_since_attack = 0.0f;

DemoLayer2::DemoLayer2() : Layer("DemoLayer2") {}

void DemoLayer2::onAttach() {
    _enemy_texture_id = AssetManager::LoadTextureFile("assets/saracen.png");
    _enemies.emplace_back(_enemy_texture_id, 50, 60, 50, 100, 10, 10);
    _enemies.emplace_back(_enemy_texture_id, 50, 60, 50, 100, 50, 50);
    _enemies.emplace_back(_enemy_texture_id, 50, 60, 50, 100, 100, 400);
    _enemies.emplace_back(_enemy_texture_id, 50, 60, 50, 100, 500, 20);
    _enemies.emplace_back(_enemy_texture_id, 50, 60, 50, 100, 500, 500);
    
    for (auto &enemy : _enemies)
    {
        enemy.setXPos(700);
    }

    _player_texture_id = AssetManager::LoadTextureFile("assets/crusader.png");
    _player = new Player(_player_texture_id, 50, 70, 90, 200);
}

void DemoLayer2::onDetach()
{
    delete _player;
}

void DemoLayer2::onUpdate(float elapsed_time)
{
    static bool all_dead = true;

    if (_player->getHealth() == 0)
    {
        if (all_dead == false)
        {
            all_dead = true;
            SHTOS_LOG_WARN("Score: %d", _player->getScore());
        }
        return;
    }

    _time_since_attack += elapsed_time;
    all_dead = true;
    for (auto &enemy : _enemies)
    {
        if(!enemy.isDead())
        {
            all_dead = false;
            enemy.move(0.5f * elapsed_time * (_player->getXPos() - enemy.getXPos() + (std::rand() % 101) - 50), 0.5f * elapsed_time * (_player->getYPos() - enemy.getYPos() + (std::rand() % 101) - 50));
            enemy.render();
            enemy.attack(_player, elapsed_time);
        }
    }

    if (all_dead)
    {
        int enemies_count = _enemies.size() * 2;
        _enemies.clear();
        for (int i = 0; i < enemies_count; ++i)
        {
            _enemies.emplace_back(_enemy_texture_id, 50, 60, 50, 100, 700, std::rand() % 600 + 100);
        }
    }

    _player->move(elapsed_time * _player_motion_x, elapsed_time * _player_motion_y);
    _player_motion_x = 0.0f;
    _player_motion_y = 0.0f;

    if (_time_since_attack > 0.2f)
    {
        if (_time_since_attack > 0.25f && _was_attack)
        {
            _player->swordRight();
            SHTOS_LOG_INFO("Actually attacking");
            for (auto &enemy : _enemies)
            {
                _player->attack(enemy);
            }
            _was_attack = false;
            _time_since_attack = 0;
        }
        else
        {
            _player->swordUp();
        }
    }

    _player->render();
}

void DemoLayer2::handleEvents(EventHandler *myEventHandler)
{
    static const float scale = 150.0f;

    //W BUTTON implementation
    if(myEventHandler->KeyDown(SDL_SCANCODE_W))
    {
        //SHTOS_LOG_INFO("Layer 2: W DOWN");
        _player_motion_y -= scale;
    }

    //S BUTTON implementation
    if(myEventHandler->KeyDown(SDL_SCANCODE_S))
    {
        //SHTOS_LOG_INFO("Layer 2: S DOWN");
        _player_motion_y += scale;
    }

    //A BUTTON implementation
    if(myEventHandler->KeyDown(SDL_SCANCODE_A))
    {
        //SHTOS_LOG_INFO("Layer 2: A DOWN");
        _player_motion_x -= scale;
    }

    //D BUTTON implementation
    if(myEventHandler->KeyDown(SDL_SCANCODE_D))
    {
        //SHTOS_LOG_INFO("Layer 2: D DOWN");
        _player_motion_x += scale;
    }

    if(myEventHandler->KeyPressed(SDL_SCANCODE_SPACE))
    {
        _was_attack = true;
        SHTOS_LOG_INFO("SWING THAA BLAAAAAAADE\n");
        printf("Your hp:%d\n", _player->getHealth());
    }
}

