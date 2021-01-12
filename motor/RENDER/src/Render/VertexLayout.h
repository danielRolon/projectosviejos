#pragma once

#include <vector>

struct VertexAttribute
{
    int size = 0;
    bool normalized = false;
};

class VertexLayout
{
public:
    explicit VertexLayout(int size);

    const VertexAttribute& operator[](unsigned int index)
    {
        return attributes[index];
    }

    void addAttribute(int size, bool normalized);

    inline unsigned int getID()     { return vbo;    }
    inline unsigned int getCount()  { return count;  }
    inline unsigned int getStride() { return stride; }
private:
    unsigned int vbo;
    unsigned int count  = 0;
    unsigned int stride = 0;
    std::vector<VertexAttribute> attributes;
};