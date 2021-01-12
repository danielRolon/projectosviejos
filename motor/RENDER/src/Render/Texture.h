#pragma once

#include <stdlib.h>
#include <string>
#include <unordered_map>

class Texture
{
public:
    Texture(const std::string& file);
    ~Texture();

    void use(size_t slot = 0) const;
    size_t textureID;
    std::string filepath;
    unsigned char* localBuffer = nullptr;
    int width, height, BPP;
};