#ifndef TEXTURE_HPP
#define TEXTURE_HPP

#include <iostream>

#include <GL/glew.h>

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
