#ifndef GAME_HPP
#define GAME_HPP

#include <iostream>
#include <unordered_map>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

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

    unsigned int m_screen_width, m_screen_height;

    Game_State m_game_state;

    Level *m_current_level;
    Player *m_player;

    Shader *m_shader;
    Texture *m_texture;
    unsigned int m_VAO, m_VBO, m_EBO;

    void init_main_menu();

};

#endif // GAME_HPP
