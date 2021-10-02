#include "sprite.hpp"

Sprite::Sprite(const char *path, glm::vec2 pos) {

    m_texture = new Texture(path, true);
}

Sprite::~Sprite() {

    if (m_texture != NULL) {
        delete m_texture;
    }
}
