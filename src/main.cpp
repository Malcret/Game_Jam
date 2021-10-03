#include <SFML/Graphics.hpp>

#include "game.hpp"

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600

int main() {
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "The lost pixel");

    Game *m_game = new Game(window, WINDOW_WIDTH, WINDOW_HEIGHT);

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
