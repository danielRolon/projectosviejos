#include <Render/Shader.h>
#include <iostream>

#include <fstream>
#include <stdio.h>
#include <sstream>

#include <GL/glew.h>

Shader::Shader(const std::string& path_Vs, const std::string& path_Fs)
{
    std::string vertexShaderSource = loadShader(path_Vs);
    std::string fragmentShaderSource = loadShader(path_Fs);

    unsigned int vertexShader = compileShader(GL_VERTEX_SHADER , vertexShaderSource);
    unsigned int fragmentShader = compileShader(GL_FRAGMENT_SHADER , fragmentShaderSource);

    /*printf(path_Vs.c_str());
    printf("\n");
    printf(path_Fs.c_str());*/

    // Create Program
    shaderProgram = glCreateProgram();

    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);
    glValidateProgram(shaderProgram);

    /*int  success;
    char infoLog[512];
    glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);

    if(!success) {
        glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER_PROGRAM::LINKING\n";
    }*/

    glUseProgram(shaderProgram);

    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);  
}

Shader::~Shader()
{
    glDeleteShader(shaderProgram);
    glUseProgram(0);
}

void Shader::use() const
{
    glUseProgram(shaderProgram);
}

const std::string Shader::loadShader(const std::string& pathShader) const
{
    std::ifstream fileShader(pathShader);
    std::stringstream textShader;
    std::string line;

    if (fileShader.fail())
    {
        fprintf(stderr, "Error! escribi la ruta bien mogolico! >:ù");
    }

    while(getline(fileShader, line))
    {
        textShader << line << '\n';
    }

    return textShader.str();
}

unsigned int Shader::compileShader(unsigned int type, const std::string& sourceShader) const
{

    unsigned int shaderID;
    shaderID = glCreateShader(type);
    
    const char *sss = sourceShader.c_str(); // AUXILIAR
    glShaderSource(shaderID, 1, &sss, nullptr);
    glCompileShader(shaderID);

    int  success;
    char infoLog[512];
    glGetShaderiv(shaderID, GL_COMPILE_STATUS, &success);

    if(!success)
    {
        glGetShaderInfoLog(shaderID, 512, nullptr, infoLog);
        std::cout << "ERROR::SHADER::" << (type == GL_VERTEX_SHADER ? "VERTEX" : "FRAGMENT") << "::COMPILATION_FAILED\n" << infoLog << "\n";
    }

    return shaderID;
}

// Uniforms
void Shader::setUniform1i(const std::string& name, int value)
{
    glUniform1i(getUniformLocation(name), value);
}

void Shader::setUniform1f(const std::string& name, float value)
{
    glUniform1f(getUniformLocation(name), value);
}

void Shader::setUniform4f(const std::string& name, float v0, float v1, float v2, float v3)
{
    glUniform4f(getUniformLocation(name), v0, v1, v2, v3);
}   

void Shader::setUniform1iv(const std::string& name, unsigned int length, int* samplers)
{
    glUniform1iv(getUniformLocation(name), length, samplers);
}

void Shader::setUniformMatrix4fv(const std::string& name, float* matrix)
{
    glUniformMatrix4fv(getUniformLocation(name), 1, GL_FALSE, matrix);
}

unsigned int Shader::getUniformLocation(const std::string& name)
{
    auto it_Name = uniformLocationCache.find(name);

    if (it_Name != uniformLocationCache.end())
    {
        return it_Name->second;
    }

    int location = glGetUniformLocation(shaderProgram, name.c_str());

    if (location == -1)
        std::cout << "Warning: that uniform '"<< name << "' doesn't exist!\n";

    uniformLocationCache[name] = location;
    return location;
}