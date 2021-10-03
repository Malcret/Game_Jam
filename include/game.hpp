#ifndef GAME_HPP
#define GAME_HPP

#include <iostream>

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

    Game(sf::RenderWindow &window, unsigned int screen_width, unsigned int screen_height);
    
    ~Game();

    void loop();

private:

    sf::RenderWindow &m_window;
    unsigned int m_screen_width, m_screen_height;

    Game_State m_game_state;

    sf::Texture m_background_texture;
    sf::Sprite m_background_sprite;

    void init_main_menu();

};

#endif // GAME_HPP
