#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <SFML/Graphics.hpp>

#define PLAYER_VELOCITY 10

class Player {

public:

    Player(const char *name, unsigned int default_madness, unsigned int default_health);

    ~Player();

    void set_pos(sf::Vector2f pos);
    void move(sf::Vector2f pos) {
        m_pos += pos;
    }

private:

    const char *m_name;
    unsigned int m_default_madness;
    unsigned int m_madness;
    unsigned int m_default_health;
    unsigned int m_health;
    sf::Vector2f m_pos;

};

#endif // PLAYER_HPP
