#include <Render/VertexLayout.h>
#include <GL/glew.h>

VertexLayout::VertexLayout(int size)
{
    glGenBuffers(1, &vbo);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, size, nullptr, GL_DYNAMIC_DRAW);
}

void VertexLayout::addAttribute(int size, bool normalized)
{
    attributes.push_back({size, normalized});
    ++count;
    stride += size * sizeof(float);
}