#include <SFML/Graphics.hpp>

#include "game.hpp"

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600

int main() {
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "The lost pixel");


    std::vector<const char*> events;
    std::vector<const char*> tracks;
    tracks.push_back("sounds/LVL1_KALM.wav");
    tracks.push_back("sounds/LVL1_NOICE.wav");
    tracks.push_back("sounds/LVL1_PANIK.wav");
    tracks.push_back("sounds/LVL2_KALM.wav");
    tracks.push_back("sounds/LVL2_NOICE.wav");
    tracks.push_back("sounds/LVL2_PANIK.wav");
    tracks.push_back("sounds/TITLE_THEME.wav");
    Game *m_game = new Game(window, WINDOW_WIDTH, WINDOW_HEIGHT, tracks, events);

    while (window.isOpen()) {
        // Poll events
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Clear screen
        window.clear(sf::Color::Black);
        // Run
        m_game->loop();
        // Display sprites
        window.display();
    }

    delete m_game;

    return 0;
}
