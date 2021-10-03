#include "game.hpp"

Game::Game(sf::RenderWindow &window, unsigned int screen_width, unsigned int screen_height)
    : m_window(window), m_screen_width(screen_width), m_screen_height(screen_height) {

    m_game_state = Game_State::MAIN_MENU;
    load_textures();
    init_main_menu();
}

Game::~Game() {

}

void Game::load_textures() {
    if (m_background_texture.loadFromFile("textures/Title.png")) {
        std::cerr << "failed to load texture : textures/Title.png" << std::endl;
    }
}

void Game::init_main_menu() {

    m_background_sprite.setTexture(m_background_texture);
    m_background_sprite.setScale(sf::Vector2f((float)m_screen_width / (float)m_background_texture.getSize().x, (float)m_screen_height / (float)m_background_texture.getSize().y));
}

void Game::loop() {

    get_keyboard_input();
    get_mouse_input();
    get_mouse_pos();

    m_window.draw(m_background_sprite);
}

void Game::get_keyboard_input() {
    if (m_game_state == Game_State::GAME) {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            m_player->move(sf::Vector2f(10.0f * m_delta_time, 10.0f * m_delta_time));
        }
    }
}

void Game::get_mouse_input() {

}

void Game::get_mouse_pos() {

}
