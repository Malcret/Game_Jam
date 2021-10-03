#include "game.hpp"

Game::Game(sf::RenderWindow &window, unsigned int screen_width, unsigned int screen_height)
    : m_window(window), m_screen_width(screen_width), m_screen_height(screen_height) {

    m_game_state = Game_State::MAIN_MENU;
    init_main_menu();
}

Game::~Game() {

}

void Game::init_main_menu() {

    if (!m_background_texture.loadFromFile("textures/Title.png")); {
        std::cerr << "failed to load texture" << std::endl;
    }
    m_background_sprite.setTexture(m_background_texture);

}

void Game::loop() {

    m_window.draw(m_background_sprite);
}
