#include "game.hpp"

Game::Game(sf::RenderWindow &window, Settings &settings, std::vector< const char*> tracks, std::vector< const char*> events) 
    : m_window(window), m_settings(settings), sound(Sound(tracks, events)){

    m_level = NULL;
    load_textures();
    load_main_menu();
}

Game::~Game() {

    for (auto it = m_textures_map.begin(); it != m_textures_map.end(); ++it) {
        if (it->second != NULL) {
            delete it->second;
        }
    }
}

void Game::add_texture(const char *name, const char *path) {
    m_textures_map[name] = new sf::Texture();
    if (!m_textures_map[name]->loadFromFile(path)) {
        std::cerr << "ERROR: Failed to load texture : " << path << std::endl;
    }
}

void Game::load_textures() {
    add_texture("main_menu_background", "textures/Title_without_boxes.png");
    add_texture("selector", "textures/selector.png");
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

    m_level = new Level(m_window, m_settings, m_textures_map, nb);
    m_game_level = (Game_Level)nb;
}

void Game::loop() {
    m_current_frame = m_clock.getElapsedTime().asSeconds();
    m_delta_time = m_current_frame - m_last_frame;
    m_last_frame = m_current_frame;

    get_keyboard_input();
    get_mouse_input();
    get_mouse_pos();

    m_level->draw(m_delta_time);

    if (m_game_level == Game_Level::MAIN_MENU) {
        sound.playTrack("sounds/TITLE_THEME.wav");
    }
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