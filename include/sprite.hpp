#ifndef SPRITE_HPP
#define SPRITE_HPP

#include <glm/glm.hpp>

#include "texture.hpp"

class Sprite {

public:

    Sprite(const char *path, glm::vec2 pos = glm::vec2(0.0f, 0.0f));

    ~Sprite();

private:

    Texture *m_texture;
    glm::vec2 pos;
};

#endif // SPRITE_HPP
