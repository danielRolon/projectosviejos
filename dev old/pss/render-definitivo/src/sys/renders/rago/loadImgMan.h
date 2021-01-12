#pragma once

#include <unordered_map>
#include <string>

#include <allegro5/allegro.h>

class LoadImgMan {
public:
    static ALLEGRO_BITMAP* LoadImage(const std::string& imagePath);
private:
    static std::unordered_map<std::string, ALLEGRO_BITMAP*> imgsLoadedCache;
};