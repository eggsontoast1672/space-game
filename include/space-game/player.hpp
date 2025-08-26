#pragma once

#include <forward_list>

#include <SFML/Graphics.hpp>

#include "space-game/bullet.hpp"

// Okay, so this definitely does not belong in this file. However, the player is
// the only thing that needs this info right now (besides main), so this is
// where it is going.
constexpr sf::Vector2u screen_size{1600, 900};

class Player : public sf::Drawable {
public:
    Player();

    void on_key_pressed(const sf::Event::KeyPressed *event);
    void update(float dt);
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

private:
    static constexpr float speed = 325;

    std::forward_list<Bullet> m_bullets;
    sf::Texture m_texture;
    sf::Sprite m_sprite;

    void collide_screen_top();
    void collide_screen_bottom();
};
