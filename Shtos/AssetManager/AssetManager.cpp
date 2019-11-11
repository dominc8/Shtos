#include "AssetManager/AssetManager.h"
#include "Logger/Logger.h"

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include <assert.h>
#include <string.h>
#include <string>

struct Asset
{
    Asset(const char *filepath, AssetType init_type, void *init_data = NULL) : path(filepath), type(init_type), data(init_data) 
    {
        SHTOS_LOG_INFO("Creating Asset with path %s\n", path.c_str());
    }

    ~Asset()
    {
        if (AssetType::SURFACE == type)
        {
            SHTOS_LOG_INFO("Free Surface %s\n", path.c_str());
            SDL_FreeSurface((SDL_Surface*)data);
        }
        else if (AssetType::TEXTURE == type)
        {
            SHTOS_LOG_INFO("Destroy Texture %s\n", path.c_str());
            SDL_DestroyTexture((SDL_Texture*)data);
        }
    }

    const std::string path;
    AssetType type;
    void *data;
};

std::vector<Asset*> AssetManager::_assets;
uint16_t AssetManager::_size = 0;
bool AssetManager::_initialized = false;
char *AssetManager::_base_path = NULL;

void AssetManager::Initialize()
{
    if (!_initialized)
    {
        SHTOS_LOG_INFO("Initializing AssetManager!\n");
        _assets.reserve(10);
        _size = 0;
        _base_path = SDL_GetBasePath();
        _initialized = true;
    }
}

void AssetManager::Deinitialize()
{
    SHTOS_LOG_INFO("Deinitializing AssetManager\n");
    for (uint16_t i = 0; i < _size; ++i)
    {
        delete _assets[i];
    }
    _size = 0;
    SDL_free(_base_path);
    _initialized = false;
}

SDL_Texture* AssetManager::GetTexture(uint16_t texture_id)
{
    assert(_initialized);
    SDL_Texture *texture_ptr = NULL;
    if (texture_id < _size)
    {
        if (AssetType::TEXTURE == _assets[texture_id]->type)
        {
            texture_ptr = (SDL_Texture*)_assets[texture_id]->data;
        }
    }
    if (NULL == texture_ptr)
    {
        SHTOS_LOG_ERR("AssetManager::GetTexture is returning NULL!\n");
    }
    return texture_ptr;
}


uint16_t AssetManager::LoadTextureFile(const char* filepath)
{
    assert(_initialized);
    for (uint16_t i = 0; i < _size; ++i)
    {
        if (!strcmp(_assets[i]->path.c_str(), filepath))
        {
            return i;
        }
    }
    SHTOS_LOG_INFO("Loading %s texture file as surface with id %u\n", filepath, _size);
    char absolute_path[200];
    strcpy(absolute_path, _base_path);
    strcpy(absolute_path + strlen(_base_path), filepath);
    SDL_Surface *surface_ptr = IMG_Load(absolute_path);
    if (NULL == surface_ptr)
    {
        SHTOS_LOG_ERR("Couldn't load %s texture file!\n", absolute_path);
        SHTOS_LOG_ERR("SDL_ERROR: %s\n", SDL_GetError());
        return -1;
    }
    Asset *newSurface = new Asset(absolute_path, AssetType::SURFACE);
    newSurface->data = surface_ptr;
    _assets.emplace_back(newSurface);
    ++_size;
    return _size - 1;
}

uint16_t AssetManager::LoadTexture(SDL_Renderer *renderer, uint16_t asset_id)
{
    assert(_initialized);
    uint16_t ret_id;
    if (asset_id < _size)
    {
        if (AssetType::TEXTURE == _assets[asset_id]->type)
        {
            ret_id = asset_id;
        }
        else if (AssetType::SURFACE == _assets[asset_id]->type)
        {
            SHTOS_LOG_INFO("Creating texture from surface with id %u\n", asset_id);
            SDL_Texture *texture_ptr = SDL_CreateTextureFromSurface(renderer, (SDL_Surface*)_assets[asset_id]->data);
            SDL_FreeSurface((SDL_Surface*)_assets[asset_id]->data);
            _assets[asset_id]->data = texture_ptr;
            _assets[asset_id]->type = AssetType::TEXTURE;
            ret_id = asset_id;
        }
        else
        {
            ret_id = asset_id + 1;
        }
    }
    else
    {
        ret_id = asset_id - 1;
    }
    return ret_id;
}

