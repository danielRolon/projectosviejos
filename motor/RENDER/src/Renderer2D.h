#pragma once

#define SCREEN_WIDTH  500
#define SCREEN_HEIGHT 500

#define PI 3.14159

#include <string>

class GLFWwindow;

class Renderer2D
{
public:
    Renderer2D() = delete;
    Renderer2D(const Renderer2D&) = delete;
    Renderer2D& operator=(const Renderer2D&) = delete;

    static int Init();
    static void Terminate();

    static void Close();
    static bool Events();

    static void Clear();
    static void Refresh();

    // Primitives
    static void SetPointWidth(float lineWidth);
    static void SetColor(float r, float g, float b);
    static void SetAlpha(float alpha);
    static void DrawRect(float x, float y, float w, float h);
    static void DrawLine(float x0, float y0, float x1, float y1);

    // Image
    static void LoadTexture(const std::string& name, const std::string& path);
    static void DrawTexture(float x, float y, float w, float h, const std::string& name);
    static void DrawTexture(float x, float y, float w, float h, float xTex, float yTex, float wTex, float hTex, const std::string& name);
private:
    inline static GLFWwindow* window = nullptr;
    inline static float R = 1, G = 1, B = 1, A = 1;
    inline static float lineWidth = 1;
};