#include <sys/renders/rago/loadImgMan.h>

std::unordered_map<std::string, ALLEGRO_BITMAP*> LoadImgMan::imgsLoadedCache;

ALLEGRO_BITMAP* LoadImgMan::LoadImage(const std::string& imagePath) {
    auto imgIt = imgsLoadedCache.find(imagePath);
    if (imgIt == imgsLoadedCache.end()) {
        imgsLoadedCache[imagePath] = al_load_bitmap(imagePath.c_str());;
        return imgsLoadedCache[imagePath];
    }

    return imgIt->second;
}