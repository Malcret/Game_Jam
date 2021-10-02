#include "game.hpp"

Game::Game(GLFWwindow *window, unsigned int screen_width, unsigned int screen_height)
    : m_window(window), m_screen_width(screen_width), m_screen_height(screen_height) {

    m_game_state = Game_State::MAIN_MENU;
    m_shader = new Shader("shaders/sprite.vert", "shaders/sprite.frag");
    init_main_menu();
}

Game::~Game() {

    for (auto it = m_texture_map.begin(); it != m_texture_map.end(); ++it) {
        delete_texture(it->first);
    }

    delete m_background_sprite;
}

void Game::init_texture(const char *name, const char *path, bool alpha) {

    m_texture_map[name] = new Texture(path, alpha);
}

void Game::delete_texture(const char *name) {

    if (m_texture_map[name] != NULL) {
        delete m_texture_map[name];
        m_texture_map.erase(name);
    }
}

void Game::init_main_menu() {

    m_background_sprite = new Sprite(m_shader, "textures/Title.png");
}

void Game::loop() {
    
    m_background_sprite->draw();
}
