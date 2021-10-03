#include <SFML/Graphics.hpp>

#include "settings.hpp"
#include "game.hpp"

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600

int main() {

    Settings m_settings = loadSettings();
    sf::RenderWindow m_window(sf::VideoMode(m_settings.window_width, m_settings.window_height), "The lost pixel");

    std::vector<const char*> events;
    std::vector<const char*> tracks;
    tracks.push_back("sounds/LVL1_KALM.wav");
    tracks.push_back("sounds/LVL1_NOICE.wav");
    tracks.push_back("sounds/LVL1_PANIK.wav");
    tracks.push_back("sounds/LVL2_KALM.wav");
    tracks.push_back("sounds/LVL2_NOICE.wav");
    tracks.push_back("sounds/LVL2_PANIK.wav");
    tracks.push_back("sounds/TITLE_THEME.wav");
    Game *m_game = new Game(m_window, m_settings, tracks, events);

    while (m_window.isOpen()) {
        // Poll events
        sf::Event event;
        while (m_window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                m_window.close();
        }

        // Clear screen
        m_window.clear(sf::Color::Black);
        // Run
        m_game->loop();
        // Display sprites
        m_window.display();
    }

    delete m_game;

    return 0;
}
