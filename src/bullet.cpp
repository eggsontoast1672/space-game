#include "space-game/bullet.hpp"

#include <random>

static sf::Texture choose_bullet_texture() {
    std::mt19937 rng;
    std::uniform_int_distribution<int> dist(0, 1);
    return sf::Texture(std::format("assets/bullet{}.png", dist(rng)));
}

Bullet::Bullet(sf::Vector2f position)
    : m_texture(choose_bullet_texture()), m_sprite(m_texture) {
    auto size = m_texture.getSize();

    m_sprite.setOrigin({size.x / 2.0f, size.y / 2.0f});
    m_sprite.setPosition(position);
    m_sprite.setRotation(sf::degrees(90.0f));
    m_sprite.setScale({10.0f, 10.0f});
}

void Bullet::update(float dt) { m_sprite.move({speed * dt, 0.0f}); }

void Bullet::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(m_sprite);
}
