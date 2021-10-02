#include "game.hpp"

Game::Game(GLFWwindow *window, unsigned int screen_width, unsigned int screen_height)
    : m_window(window), m_screen_width(screen_width), m_screen_height(screen_height) {

}

Game::~Game() {

    for (auto it = m_texture_map.begin(); it != m_texture_map.end(); ++it) {
        delete_texture(it->first);
    }
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
    
}
