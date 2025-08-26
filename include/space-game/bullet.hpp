#pragma once

#include <SFML/Graphics.hpp>

class Bullet : public sf::Drawable {
public:
    Bullet(sf::Vector2f position);

    void update(float dt);
    void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

private:
    static constexpr float speed = 500;

    sf::Texture m_texture;
    sf::Sprite m_sprite;
};
