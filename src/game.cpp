#include "game.hpp"

Game::Game(sf::RenderWindow &window, unsigned int screen_width, unsigned int screen_height)
    : m_window(window), m_screen_width(screen_width), m_screen_height(screen_height) {

    m_level = NULL;

    load_textures();
    load_main_menu();
}

Game::~Game() {

}

void Game::load_textures() {

    m_textures_map["main_menu_background"] = new sf::Texture();
    if (!m_textures_map["main_menu_background"]->loadFromFile("textures/Title.png")) {
        std::cerr << "failed to load texture : textures/Title.png" << std::endl;
    }
}

void Game::load_main_menu() {

    m_game_state = Game_State::MENU;
    m_game_level = Game_Level::MAIN_MENU;
    load_level(0);
}

void Game::load_level(unsigned int nb) {

    if (!m_level == NULL) {
        delete m_level;
        m_level = NULL;
    }

    m_level = new Level(m_window, m_textures_map, nb);
    m_game_level = (Game_Level)nb;
}

void Game::loop() {

    m_current_frame = m_clock.getElapsedTime().asSeconds();
    m_delta_time = m_current_frame - m_last_frame;
    m_last_frame = m_current_frame;
    std::cout << m_delta_time << std::endl;

    get_keyboard_input();
    get_mouse_input();
    get_mouse_pos();

    m_level->draw(m_delta_time);
}

void Game::get_keyboard_input() {

    if (m_game_level == Game_Level::MAIN_MENU) {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
            load_level(1);
        }
    }

    if (m_game_level != Game_Level::MAIN_MENU && m_game_state == Game_State::RUN) {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            m_player->move(sf::Vector2f(PLAYER_VELOCITY * m_delta_time, PLAYER_VELOCITY * m_delta_time));
        }
    }
}

void Game::get_mouse_input() {

}

void Game::get_mouse_pos() {

}
