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
    RUN,
    PAUSE,
    MENU
};

enum class Game_Level {
    MAIN_MENU,
    LEVEL_1,
    LEVEL_2,
    LEVEL_3,
    LEVEL_4
};

class Game {

public:

    Game(sf::RenderWindow &window, unsigned int screen_width, unsigned int screen_height);
    
    ~Game();

    void loop();

private:

    sf::RenderWindow &m_window;
    unsigned int m_screen_width, m_screen_height;

    Game_State m_game_state;
    Game_Level m_game_level;

    sf::Clock m_clock;
    float m_delta_time;
    float m_current_frame;
    float m_last_frame;

    std::unordered_map<const char *, sf::Texture *> m_textures_map;

    Level *m_level;
    Player *m_player;

    void load_textures();
    void load_main_menu();
    void load_level(unsigned int nb);

    void get_keyboard_input();
    void get_mouse_input();
    void get_mouse_pos();    

};

#endif // GAME_HPP
