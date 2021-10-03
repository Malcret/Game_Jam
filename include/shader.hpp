#ifndef SHADER_H
#define SHADER_H

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

#include <GL/glew.h>

#include <glm/glm.hpp>

class Shader {

public:

    Shader(const char* vertexPath, const char* fragmentPath);

    // Return shader ID
    const unsigned int &getID();

    // Activate shader
    void use();

    // Uniform functions
    void setBool(const char *name, bool value) const;
    void setInt(const char *name, int value) const;
    void setFloat(const char *name, float value) const;
    void setVec2(const char *name, glm::vec2 vector) const;
    void setVec2(const char *name, const float x, const float y) const;
    void setVec3(const char *name, glm::vec3 vector) const;
    void setVec3(const char *name, const float x, const float y, const float z) const;
    void setVec4(const char *name, glm::vec4 vector) const;
    void setVec4(const char *name, const float x, const float y, const float z, const float w) const;
    void setMat2(const char *name, glm::mat2 matrix) const;
    void setMat3(const char *name, glm::mat3 matrix) const;
    void setMat4(const char *name, glm::mat4 matrix) const;

private:

    unsigned int m_ID;

    // Utility function for checking shader compilation/linking errors.
    void checkCompileErrors(unsigned int shader, std::string type);
};

#endif
