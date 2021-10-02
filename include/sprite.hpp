#ifndef SPRITE_HPP
#define SPRITE_HPP

#include <glm/glm.hpp>

#include "shader.hpp"
#include "texture.hpp"

class Sprite {

public:

    Sprite(Shader *shader, const char *path, glm::vec2 pos = glm::vec2(0.0f, 0.0f));

    ~Sprite();

    void draw();

private:

    unsigned int m_VBO, m_VAO, m_EBO;

    Shader *m_shader;
    Texture *m_texture;
    glm::vec2 pos;
};

#endif // SPRITE_HPP
