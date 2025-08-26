#include <SFML/Graphics.hpp>

#include "space-game/player.hpp"

int main() {
    sf::RenderWindow window(sf::VideoMode(screen_size), "C++ Game");

    sf::Texture bg_texture("assets/background.png");
    sf::Sprite bg_sprite(bg_texture);
    bg_sprite.setScale({1920.0f / bg_sprite.getGlobalBounds().size.x,
                        1080.0f / bg_sprite.getGlobalBounds().size.y});

    Player player;

    sf::Clock clock;

    while (window.isOpen()) {
        float dt = clock.restart().asSeconds();

        while (auto event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>()) {
                window.close();
            } else if (const auto *key_pressed =
                           event->getIf<sf::Event::KeyPressed>()) {
                player.on_key_pressed(key_pressed);
            }
        }

        player.update(dt);

        window.clear();
        window.draw(bg_sprite);
        window.draw(player);
        window.display();
    }
}
