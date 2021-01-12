#pragma once

#include <string>
#include <unordered_map>

class Shader
{
public:
    Shader(const std::string& path_Vs, const std::string& path_Fs);
    ~Shader();

    void use() const;
    inline unsigned int getID() const
    {
        return shaderProgram;
    }

    // Uniforms
    void setUniform1i(const std::string& name, int value);
    void setUniform1f(const std::string& name, float value);
    void setUniform4f(const std::string& name, float v0, float v1, float v2, float v3);
    void setUniform1iv(const std::string& name, unsigned int length, int* samplers);
    void setUniformMatrix4fv(const std::string& name, float* matrix);

private:
    enum class TYPE_SHADER
    {
        VERTEX,
        FRAGMENT
    };
    unsigned int shaderProgram;
    std::unordered_map<std::string, unsigned int> uniformLocationCache;


private:
    const std::string loadShader(const std::string& pathShader) const;
    unsigned int compileShader(unsigned int type, const std::string& sourceShader) const;
    unsigned int getUniformLocation(const std::string& name);
};