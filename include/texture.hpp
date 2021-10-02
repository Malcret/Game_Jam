#ifndef TEXTURE_HPP
#define TEXTURE_HPP

#include <iostream>

#include <GL/glew.h>

#define STB_IMAGE_IMPLEMENTATION
#include "stb/stb_image.h"

class Texture {

public:

    Texture(const char *path, bool alpha = false);

    // Return texture ID
    const unsigned int &getID();

    // Activate Texture
    void use();

private:

    unsigned int m_ID;
};

#endif // TEXTURE_HPP
