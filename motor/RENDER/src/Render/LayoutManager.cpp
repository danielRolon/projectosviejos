#include <Render/LayoutManager.h>
#include <Render/VertexLayoutManager.h>
#include <GL/glew.h>

LayoutManager::LayoutManager(unsigned int maxVertices, unsigned int sizeVertex, std::vector<float>& attribsLayout, Shader* shader)
{
    verticesAttributes.reserve(maxVertices * sizeVertex);

    VertexLayoutManager vertexLayoutManager;
    layout = new VertexLayout(maxVertices * (sizeVertex * sizeof(float)));

    for (unsigned int i = 0; i < attribsLayout.size(); ++i)
    {
        layout->addAttribute(attribsLayout[i], false);
    }

    vertexLayoutManager.addLayout(*layout);

    this->shader = shader;
    //this->shader->use();
}

LayoutManager::~LayoutManager()
{
    delete layout;
    delete shader;
}

void LayoutManager::addVertex(const std::vector<float>& attributes)
{
    for (unsigned int i = 0; i < attributes.size(); ++i)
    {
        verticesAttributes.emplace_back(attributes[i]);
    }
}

void LayoutManager::drawAllVertex(unsigned int maxIndices)
{
    shader->use();
    glBindBuffer(GL_ARRAY_BUFFER, layout->getID());
    glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(float) * verticesAttributes.size(), verticesAttributes.data());

    glDrawElements(GL_TRIANGLES, maxIndices, GL_UNSIGNED_INT, nullptr);

    verticesAttributes.clear();
}
