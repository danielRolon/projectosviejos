#pragma once

/* Esta clase se encarga de manejar un diseño de vertice especifico */

#include <vector>
#include <Render/Shader.h>

class VertexLayout;

class LayoutManager
{
public:
    LayoutManager(unsigned int maxVertices, unsigned int sizeVertex, std::vector<float>& attribsLayout, Shader* shader);
    ~LayoutManager();

    inline        unsigned int getID() const { return ID; }
    inline static unsigned int GetID()       { return ID; }

    void addVertex(const std::vector<float>& attributes);
    void drawAllVertex(unsigned int maxIndices);

    //inline *Shader getShader()               { return shader;   }
    //inline void    setShader(Shader* shader) { this->shader = shader; }

private:
    inline static       unsigned int Count = 0;
    inline static const unsigned int ID    = ++Count;

    std::vector<float> verticesAttributes;
    VertexLayout* layout = nullptr;
    Shader*       shader = nullptr;
};