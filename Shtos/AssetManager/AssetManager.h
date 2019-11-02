#ifndef ASSETMANAGER_H
#define ASSETMANAGER_H

#include <vector>
#include <SDL2/SDL.h>

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

private:
    AssetManager();
    ~AssetManager();

    static std::vector<Asset*> _assets;
    static uint16_t _size;
    static bool _initialized;
};

#endif /* ASSETMANAGER_H */

