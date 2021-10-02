#include "player.hpp"

Player::Player(const char *name, unsigned int default_madness, unsigned int default_health)
    : m_name(name), m_default_madness(default_madness), m_default_health(default_health) {

}

Player::~Player() {

}

void Player::set_pos(glm::vec2 pos) {
    m_pos = pos;
}
