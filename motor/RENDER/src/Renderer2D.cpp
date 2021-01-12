#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <Render/Render.h>
#include <Render/Shader.h>
#include <Render/Texture.h>
#include <glm/mat4x4.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <Renderer2D.h>

const size_t MaxQuads    = 1000;
const size_t MaxVertices = MaxQuads * 4;
const size_t MaxIndices  = MaxQuads * 6;
const size_t MaxTextures = 10;

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}

int Renderer2D::Init()
{
    if (!glfwInit())
        return -1;

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_COMPAT_PROFILE);

    window = glfwCreateWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Hello World", NULL, NULL);

    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);

    if (glewInit() != GLEW_OK)
        fprintf(stderr, "Error! glew no se ah iniciado correctamente");

    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);  

    /*/////////////////////////////////////////////////////////////////////////////////////////////////
    /////////////SHADER///////////////////SHADER////////////////////////SHADER////////////////////
    *///////////////////////////////////////////////////////////////////////////////////////

    Shader* shader = new Shader("res/shaders/QuadTexVS.shader", "res/shaders/QuadTexFS.shader");

    // Maths
    glm::mat4 proj = glm::ortho(0.0f, (float) SCREEN_WIDTH, (float) SCREEN_HEIGHT, 0.0f, -1.0f, 1.0f);
    glm::mat4 view(1.0f);

    glm::mat4 VP  = proj * view;

    // Sampler
    int* samplers = new int[MaxTextures];
    
    for (unsigned int i = 0; i < MaxTextures; ++i)
    {
        samplers[i] = i;
    }

    // Uniforms
    shader->setUniform1iv("u_Textures", MaxTextures, samplers);
    shader->setUniformMatrix4fv("v_ProjectionView", glm::value_ptr(VP));

    delete[]samplers;
    
    Render::Init(5, 10, MaxIndices);
    Render::AddLayout("LayoutTex", MaxVertices, 10, {3, 4, 2, 1}, shader);

    // Blending
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);  

    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
}

void Renderer2D::Terminate()
{
    Render::Destroy();
    glfwTerminate();
}

void Renderer2D::Close()
{
    glfwSetWindowShouldClose(window, true);
}

bool Renderer2D::Events()
{
    return (!glfwWindowShouldClose(window)) ? true : false;
}

void Renderer2D::Clear()
{
    glClear(GL_COLOR_BUFFER_BIT);
}

void Renderer2D::Refresh()
{
        Render::DrawAllVertex();

        glfwSwapBuffers(window);
        
        glfwPollEvents();
}

void Renderer2D::SetPointWidth(float lineWidth)
{
    Renderer2D::lineWidth = lineWidth;
}

void Renderer2D::SetColor(float r, float g, float b)
{
    R = r;
    G = g;
    B = b;
}

void Renderer2D::SetAlpha(float alpha)
{
    A = alpha;
}


void Renderer2D::DrawRect(float x, float y, float w, float h)
{
    auto layout = Render::GetLayout("LayoutTex");

    layout->addVertex({x    , y    , 1.0, R, G, B, A, 0, 0, -1});
    layout->addVertex({x + w, y    , 1.0, R, G, B, A, 0, 0, -1});
    layout->addVertex({x + w, y + h, 1.0, R, G, B, A, 0, 0, -1});
    layout->addVertex({x    , y + h, 1.0, R, G, B, A, 0, 0, -1});
}

void Renderer2D::DrawLine(float x, float y, float x2, float y2)
{
    auto layout = Render::GetLayout("LayoutTex");

    float co = x - x2;
    float ca = y - y2;
    float a  = atan(ca/co);


    float cosa = cos((a-PI/2));
    float sina = sin((a-PI/2));

    layout->addVertex({x                    , y                    , 1.0, R, G, B, A, 0, 0, -1});
    layout->addVertex({x  + cosa * lineWidth, y  + sina * lineWidth, 1.0, R, G, B, A, 0, 0, -1});



    layout->addVertex({x2 + cosa * lineWidth, y2 + sina *  lineWidth, 1.0, R, G, B, A, 0, 0, -1});
    layout->addVertex({x2                   , y2                    , 1.0, R, G, B, A, 0, 0, -1});
}

void Renderer2D::LoadTexture(const std::string& name, const std::string& path)
{
    Render::LoadTexture(name, path);
}

void Renderer2D::DrawTexture(float x, float y, float w, float h, const std::string& name)
{
    float id = (float) Render::GetTextureID(name);

    auto layout = Render::GetLayout("LayoutTex");

    layout->addVertex({x    , y    , 1.0, R, G, B, A,  0 , 0  , id});
    layout->addVertex({x + w, y    , 1.0, R, G, B, A, 1.0, 0  , id});
    layout->addVertex({x + w, y + h, 1.0, R, G, B, A, 1.0, 1.0, id});
    layout->addVertex({x    , y + h, 1.0, R, G, B, A, 0  , 1.0, id});
}

void Renderer2D::DrawTexture(float x, float y, float w, float h, float xTex, float yTex, float wTex, float hTex, const std::string& name)
{
    float id = (float) Render::GetTextureID(name);

    auto layout = Render::GetLayout("LayoutTex");

    layout->addVertex({x    , y    , 1.0, R, G, B, A,   xTex, yTex, id});
    layout->addVertex({x + w, y    , 1.0, R, G, B, A,   wTex, yTex, id});
    layout->addVertex({x + w, y + h, 1.0, R, G, B, A,   wTex, hTex, id});
    layout->addVertex({x    , y + h, 1.0, R, G, B, A,   xTex, hTex, id});  
}