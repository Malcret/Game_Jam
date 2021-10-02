#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <glm/glm.hpp>
#include <yaml-cpp/yaml.h>
#include <fstream>
#include <string>

class Player {

public:

    Player(const char *name, unsigned int default_madness, unsigned int default_health);

    ~Player();

    void set_pos(glm::vec2 pos);
    void save();
    void initFromSave();
    void initStats();
    void move(glm::vec2 pos) {
        m_pos += pos;
    }

private:

    const char *m_name;
    unsigned int m_default_madness;
    unsigned int m_madness;
    unsigned int m_default_health;
    unsigned int m_health;
    glm::vec2 m_pos;

};

#endif // PLAYER_HPP
