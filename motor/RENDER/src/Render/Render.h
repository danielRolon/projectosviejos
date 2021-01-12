#pragma once

#include <Render/Shader.h>
#include <Render/Color.h>
#include <stdlib.h>
#include <utils/slist.h>
#include <vector>
#include <utils/slist.h>
#include <string>
#include <unordered_map>
#include <Render/Texture.h>
#include <Render/LayoutManager.h>

struct TexMetrics
{
    TexMetrics(int width, int height) : width(width), height(height) {}
    int width  = 3;
    int height = 3;
};

class VertexLayout;

class Vertex
{
    float x, y, z, r, g, b, a, xTex, yTex, texIndex;
};

class Render
{
public:
    Render() = delete;
    Render(const Render&) = delete;
    Render& operator=(const Render&) = delete;

    static void Init(size_t maxLayouts, size_t maxTextures, size_t maxIndices);
    static void Destroy();

    // Texture
    static void LoadTexture(const std::string& name, const std::string& path);
    static size_t GetTextureID(const std::string& name);
    static int GetTextureWidth(size_t id);
    static int GetTextureHeight(size_t id);

    static void AddLayout(const std::string& name, unsigned int maxVertices, unsigned int sizeVertex, std::vector<float> attribsLayout, Shader* shader);
    static LayoutManager* GetLayout(const std::string& name);

    static void DrawAllVertex();
    
private:
    inline static size_t vao, ibo;
    inline static std::unordered_map<std::string, LayoutManager*> layouts;
    inline static std::vector<std::string> namesCache;

    inline static std::vector<size_t> indices;
    inline static size_t MaxIndices = 0;

    inline static const size_t MaxTextures = 10;
    inline static       size_t TexturesCount = 0;

    inline static SList<Texture> textures = SList<Texture>(10);
    inline static std::unordered_map<std::string, size_t> texturesCache;
    inline static std::vector<TexMetrics> texMetrices;
};