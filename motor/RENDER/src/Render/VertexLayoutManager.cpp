#include <Render/VertexLayoutManager.h>
#include <GL/glew.h>

VertexLayoutManager::VertexLayoutManager()
{
}

void VertexLayoutManager::addLayout(VertexLayout& vertexLayout)
{
    unsigned int offset = 0;

    for (unsigned int i = 0; i < vertexLayout.getCount(); ++i)
    {
        glEnableVertexAttribArray(i);
        glVertexAttribPointer(i, vertexLayout[i].size, GL_FLOAT, vertexLayout[i].normalized, vertexLayout.getStride(), (void*)(offset * sizeof(float)));
    
        offset += vertexLayout[i].size;
    }
}