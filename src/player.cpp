#include "player.hpp"

Player::Player(const char *name, unsigned int default_madness, unsigned int default_health)
    : m_name(name), m_default_madness(default_madness), m_default_health(default_health) {

}

Player::~Player() {

}

void Player::initStats() {
    m_madness = m_default_madness;
    m_health = m_default_health;
    set_pos(sf::Vector2f(0,0));
}

void Player::save() {
    std::string nom(m_name);
    YAML::Node saveFile = YAML::LoadFile("save.yml");
    std::ofstream outFile("save.yml");
    saveFile["playerName"] = nom;
    saveFile["madness"] = m_madness;
    saveFile["health"] = m_health;
    saveFile["pos"]["x"] = m_pos.x;
    saveFile["pos"]["y"] = m_pos.y;
    outFile << saveFile;
    outFile.close();
}

void Player::initFromSave() {
    YAML::Node saveFile = YAML::LoadFile("save.yml");
    m_madness = saveFile["madness"].as<unsigned int>();
    m_health = saveFile["health"].as<unsigned int>();
    m_pos.x = saveFile["pos"]["x"].as<int>();
    m_pos.y = saveFile["pos"]["y"].as<int>();
    m_name = saveFile["playerName"].as<std::string>().c_str();
}

void Player::set_pos(sf::Vector2f pos) {
    m_pos = pos;
}
