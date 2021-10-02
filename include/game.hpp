#ifndef GAME_HPP
#define GAME_HPP

#include <iostream>
#include <unordered_map>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "settings.hpp"
#include "player.hpp"
#include "level.hpp"

enum class Game_State {
    MAIN_MENU,
    GAME,
    PAUSE
};

class Game {

public:

    Game(GLFWwindow *window, unsigned int screen_width, unsigned int screen_height);
    
    ~Game();

    void loop();

private:

    GLFWwindow *m_window;

    unsigned int m_screen_width;
    unsigned int m_screen_height;

    std::unordered_map<const char *, Texture *> m_texture_map;

    Game_State m_game_state;

    Level *m_current_level;
    Player *m_player;

    Shader *m_shader;
    Sprite *m_background_sprite;

    void init_texture(const char *name, const char *path, bool alpha = false);
    void delete_texture(const char *name);

    void init_main_menu();

};

#endif // GAME_HPP
