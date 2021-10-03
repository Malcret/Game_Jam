#ifndef GAME_HPP
#define GAME_HPP

#include <iostream>
#include <unordered_map>
#include <ctime>
#include <vector>

#include <SFML/Graphics.hpp>

#include "settings.hpp"
#include "player.hpp"
#include "level.hpp"
#include "sound.hpp"

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

    Game(sf::RenderWindow &window, Settings &m_settings, std::vector< const char*> tracks, std::vector< const char*> events);
    
    ~Game();

    void loop();

private:

    Settings &m_settings;
    sf::RenderWindow &m_window;

    Game_State m_game_state;
    Game_Level m_game_level;

    sf::Clock m_clock;
    float m_delta_time;
    float m_current_frame;
    float m_last_frame;

    std::unordered_map<const char *, sf::Texture *> m_textures_map;

    Level *m_level;
    Player *m_player;

    Sound sound;

    void add_texture(const char *name, const char *path);
    void load_textures();
    void load_main_menu();
    void load_level(unsigned int nb);

    void get_keyboard_input();
    void get_mouse_input();
    void get_mouse_pos();    

};

#endif // GAME_HPP
