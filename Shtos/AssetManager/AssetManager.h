#ifndef ASSETMANAGER_H
#define ASSETMANAGER_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>

#include <vector>

struct Asset;

enum class AssetType
{
    TEXTURE = 0,
    SOUND = 1,
    SURFACE = 2
};

class AssetManager
{
public:
    static void Initialize();
    static void Deinitialize();

    static SDL_Texture* GetTexture(uint16_t texture_id);

    static uint16_t LoadTextureFile(const char *filepath);
    static uint16_t LoadTexture(SDL_Renderer* renderer, uint16_t asset_id);

    static uint16_t LoadMusic(const char *filepath); 
    static bool PlayMusic(uint16_t music_id);

private:
    AssetManager();
    ~AssetManager();

    static std::vector<Asset*> _assets;
    static uint16_t _size;
    static bool _initialized;
    static char *_base_path;
};

#endif /* ASSETMANAGER_H */

