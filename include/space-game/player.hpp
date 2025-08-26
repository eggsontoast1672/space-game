#pragma once

#include <SFML/Graphics.hpp>

// Okay, so this definitely does not belong in this file. However, the player is
// the only thing that needs this info right now (besides main), so this is
// where it is going.
constexpr sf::Vector2u screen_size{1920, 1080};

class Player : public sf::Drawable {
public:
    Player();
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

private:
    sf::Texture m_texture;
    sf::Sprite m_sprite;
};
