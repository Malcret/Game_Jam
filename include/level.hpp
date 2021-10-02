#ifndef LEVEL_HPP
#define LEVEL_HPP

#include <vector>

#include "sprite.hpp"

class Level {

public:

    Level(const char *path);

    ~Level();

private:

    Texture *m_background_texture;
    std::vector<Texture *> m_foreground_textures_map;
};

#endif // LEVEL_HPP
