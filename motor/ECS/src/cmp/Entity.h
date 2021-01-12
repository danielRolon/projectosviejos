#pragma once

#include <stdlib.h>
#include <string>
#include <vector>

struct Entity
{
    explicit Entity() = default;
    size_t idEntity {++idCount};

    size_t idFhater;
    std::vector<size_t> idChilds;

    std::string tag = "nontag";
private:
    inline static size_t idCount { 0 };
};