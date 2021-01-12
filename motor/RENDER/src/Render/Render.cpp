#include <iostream>

#include <GL/glew.h>

#include <Render/Render.h>
#include <Render/VertexLayoutManager.h>

void Render::Init(size_t maxLayouts, size_t maxTextures, size_t maxIndices)
{
    MaxIndices = maxIndices;

    // reserve
    layouts.reserve(maxLayouts);
    indices.reserve(maxIndices);
    texMetrices.reserve(10);

    // indices memory
    size_t offset = 0;

    for (size_t i = 0; i < maxIndices; i += 6)
    {
        indices.emplace_back(0 + offset);
        indices.emplace_back(1 + offset);
        indices.emplace_back(2 + offset);
        indices.emplace_back(2 + offset);
        indices.emplace_back(3 + offset);
        indices.emplace_back(0 + offset);

        offset += 4;
    }

    // indices object
    glGenBuffers(1, &ibo);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, maxIndices * sizeof(float), (void*) indices.data(), GL_STATIC_DRAW);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

void Render::Destroy()
{
}

void Render::LoadTexture(const std::string& name, const std::string& path)
{
    auto it = texturesCache.find(name);

    if (it == texturesCache.end())
    {
        textures.push(new Texture(path));
        texturesCache[name] = TexturesCount;
        texMetrices.emplace_back(textures[TexturesCount].width, textures[TexturesCount].height);
        ++TexturesCount;
        //printf("width:  %d\n", textures[TexturesCount].width);
        //printf("height: %d\n", textures[TexturesCount].height);
    }
    else 
    {
        std::cout << "Warning... Texture: " << name << " already loaded. Line:" << "\n";
    }
}

size_t Render::GetTextureID(const std::string& name)
{
    auto it = texturesCache.find(name);

    if (it != texturesCache.end())
    {
        textures[it->second].use(it->second);
        return it->second;
    }

    std::cout << "Warning... Texture: " << name << " is not loaded\n";

    return 0;
}

int Render::GetTextureWidth(size_t id)
{
    return texMetrices[id].width;
}

int Render::GetTextureHeight(size_t id)
{
    return texMetrices[id].height;
}

void Render::AddLayout(const std::string& name, unsigned int maxVertices, unsigned int sizeVertex, std::vector<float> attribsLayout, Shader* shader)
{
    auto it = layouts.find(name);

    if (it == layouts.end())
    {
        layouts[name] = new LayoutManager(maxVertices, sizeVertex, attribsLayout, shader);
        namesCache.emplace_back(name);
    }
    else
    {
        std::cout << "Warning!!! already exist this name" << "\n";
    }
}

LayoutManager* Render::GetLayout(const std::string& name)
{
    auto it = layouts.find(name);

    if (it != layouts.end())
    {
        return it->second;
    }
    else
    {
        std::cout << "Warning!!! not exist this name" << "\n";
        return nullptr;
    }
}

void Render::DrawAllVertex()
{
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ibo);

    for (unsigned int i = 0; i < layouts.size(); ++i)
    {
        layouts[namesCache[i]]->drawAllVertex(MaxIndices);
    }
}
