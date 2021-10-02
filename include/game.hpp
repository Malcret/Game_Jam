#ifndef GAME_HPP
#define GAME_HPP

#include <iostream>
#include <unordered_map>

#include <GLFW/glfw3.h>

#include "settings.hpp"
#include "shader.hpp"
#include "texture.hpp"
#include "player.hpp"
#include "level.hpp"

class Game {

public:

    Game(GLFWwindow *window, unsigned int screen_width, unsigned int screen_height);
    
    ~Game();

private:

    GLFWwindow *m_window;

    unsigned int m_screen_width;
    unsigned int m_screen_height;

    std::unordered_map<const char *, Texture *> m_texture_map;

    Level *m_current_level;
    Player *m_player;

    void init_texture(const char *name, const char *path, bool alpha = false);
    void delete_texture(const char *name);

    void init_main_menu();

};

#endif // GAME_HPP
