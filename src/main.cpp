#include <SFML/Graphics.hpp>

#include "space-game/player.hpp"

int main() {
    sf::RenderWindow window(sf::VideoMode(screen_size), "C++ Game");

    sf::Texture bg_texture("assets/background.png");
    sf::Sprite bg_sprite(bg_texture);
    bg_sprite.setScale({1920.0f / bg_sprite.getGlobalBounds().size.x,
                        1080.0f / bg_sprite.getGlobalBounds().size.y});

    Player player;

    while (window.isOpen()) {
        while (auto event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>()) {
                window.close();
            }
        }

        window.clear();
        window.draw(bg_sprite);
        window.draw(player);
        window.display();
    }
}
