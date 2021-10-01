#ifndef SHADER_H
#define SHADER_H

#include <GL/glew.h>

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

class Shader {

public:

    Shader(const char* vertexPath, const char* fragmentPath) {

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
        const char* vShaderCode = vertexCode.c_str();
        const char * fShaderCode = fragmentCode.c_str();
        
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
    const unsigned int &getID() {
        return m_ID;
    }
    // Activate shader
    void use() { 
        glUseProgram(m_ID); 
    }
    // Uniform functions
    void setBool(const std::string &name, bool value) const {         
        glUniform1i(glGetUniformLocation(m_ID, name.c_str()), (int)value); 
    }
    void setInt(const std::string &name, int value) const { 
        glUniform1i(glGetUniformLocation(m_ID, name.c_str()), value); 
    }
    void setFloat(const std::string &name, float value) const { 
        glUniform1f(glGetUniformLocation(m_ID, name.c_str()), value); 
    }

private:

    unsigned int m_ID;

    // Utility function for checking shader compilation/linking errors.
    void checkCompileErrors(unsigned int shader, std::string type) {
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
};

#endif
