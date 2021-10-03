#include "shader.hpp"

Shader::Shader(const char* vertexPath, const char* fragmentPath) {

    // Temp variables
    std::string vertexCode, fragmentCode;
    std::ifstream vShaderFile, fShaderFile;
    unsigned int m_vertex, m_fragment;

    /* Load shader files */
    // Ensure ifstream objects can throw exceptions:
    vShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
    fShaderFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
    try  {
        // Open files
        vShaderFile.open(vertexPath);
        fShaderFile.open(fragmentPath);
        std::stringstream vShaderStream, fShaderStream;
        // Read file's buffer contents into streams
        vShaderStream << vShaderFile.rdbuf();
        fShaderStream << fShaderFile.rdbuf();
        // Close file handlers
        vShaderFile.close();
        fShaderFile.close();
        // Convert stream into string
        vertexCode   = vShaderStream.str();
        fragmentCode = fShaderStream.str();
    }
    catch (std::ifstream::failure& e) {
        std::cout << "ERROR::SHADER::FILE_NOT_SUCCESFULLY_READ" << std::endl;
        exit(EXIT_FAILURE);
    }
    const char *vShaderCode = vertexCode.c_str();
    const char *fShaderCode = fragmentCode.c_str();
        
    /* Compile shaders */
    // Vertex shader
    m_vertex = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(m_vertex, 1, &vShaderCode, NULL);
    glCompileShader(m_vertex);
    checkCompileErrors(m_vertex, "VERTEX");
    // Fragment Shader
    m_fragment = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(m_fragment, 1, &fShaderCode, NULL);
    glCompileShader(m_fragment);
    checkCompileErrors(m_fragment, "FRAGMENT");
    // Shader Program
    m_ID = glCreateProgram();
    glAttachShader(m_ID, m_vertex);
    glAttachShader(m_ID, m_fragment);
    glLinkProgram(m_ID);
    checkCompileErrors(m_ID, "PROGRAM");
    // Delete the shaders as they're linked into our program now and no longer necessary
    glDeleteShader(m_vertex);
    glDeleteShader(m_fragment);
}

// Return shader ID
const unsigned int &Shader::getID() {
    return m_ID;
}
// Activate shader
void Shader::use() { 
    glUseProgram(m_ID); 
}
// Uniform functions
void Shader::setBool(const char *name, bool value) const {         
    glUniform1i(glGetUniformLocation(m_ID, name), (int)value); 
}
void Shader::setInt(const char *name, int value) const { 
    glUniform1i(glGetUniformLocation(m_ID, name), value); 
}
void Shader::setFloat(const char *name, float value) const { 
    glUniform1f(glGetUniformLocation(m_ID, name), value); 
}
void Shader::setVec2(const char *name, glm::vec2 vector) const {
    glUniform2fv(glGetUniformLocation(m_ID, name), 1, &vector[0]);
}
void Shader::setVec2(const char *name, const float x, const float y) const {
    glUniform2f(glGetUniformLocation(m_ID, name), x, y);
}
void Shader::setVec3(const char *name, glm::vec3 vector) const {
    glUniform3fv(glGetUniformLocation(m_ID, name), 1, &vector[0]);
}
void Shader::setVec3(const char *name, const float x, const float y, const float z) const {
    glUniform3f(glGetUniformLocation(m_ID, name), x, y, z);
}
void Shader::setVec4(const char *name, glm::vec4 vector) const {
    glUniform4fv(glGetUniformLocation(m_ID, name), 1, &vector[0]);
}
void Shader::setVec4(const char *name, const float x, const float y, const float z, const float w) const {
    glUniform4f(glGetUniformLocation(m_ID, name), x, y, z, w);
}
void Shader::setMat2(const char *name, glm::mat2 matrix) const {
    glUniformMatrix2fv(glGetUniformLocation(m_ID, name), 1, GL_FALSE, &matrix[0][0]);
}
void Shader::setMat3(const char *name, glm::mat3 matrix) const {
    glUniformMatrix3fv(glGetUniformLocation(m_ID, name), 1, GL_FALSE, &matrix[0][0]);
}
void Shader::setMat4(const char *name, glm::mat4 matrix) const {
    glUniformMatrix4fv(glGetUniformLocation(m_ID, name), 1, GL_FALSE, &matrix[0][0]);
}

void Shader::checkCompileErrors(unsigned int shader, std::string type) {
    int success;
    char infoLog[1024];
    if (type != "PROGRAM") {
        glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
        if (!success) {
            glGetShaderInfoLog(shader, 1024, NULL, infoLog);
            std::cout << "ERROR::SHADER_COMPILATION_ERROR of type: " << type << "\n" << infoLog << std::endl;
            exit(EXIT_FAILURE);
        }
    }
    else {
        glGetProgramiv(shader, GL_LINK_STATUS, &success);
        if (!success) {
            glGetProgramInfoLog(shader, 1024, NULL, infoLog);
            std::cout << "ERROR::PROGRAM_LINKING_ERROR of type: " << type << "\n" << infoLog << std::endl;
            exit(EXIT_FAILURE);
        }
    }
}
