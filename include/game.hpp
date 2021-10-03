#ifndef GAME_HPP
#define GAME_HPP

#include <iostream>
#include <unordered_map>
#include <ctime>

#include <SFML/Graphics.hpp>

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

    std::unordered_map<const char *, sf::Texture> m_texture_map;

    Game(sf::RenderWindow &window, unsigned int screen_width, unsigned int screen_height);
    ~Game();

    void loop();

private:

    sf::RenderWindow &m_window;
    unsigned int m_screen_width, m_screen_height;

    Game_State m_game_state;
    float m_delta_time;

    sf::Texture m_background_texture;
    sf::Sprite m_background_sprite;

    Player *m_player;

    void load_textures();
    void init_main_menu();

    void get_keyboard_input();
    void get_mouse_input();
    void get_mouse_pos();    

};

#endif // GAME_HPP
