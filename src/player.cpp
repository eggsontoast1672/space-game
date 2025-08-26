#include "space-game/player.hpp"

Player::Player() : m_texture("assets/ship.png"), m_sprite(m_texture) {
    sf::Vector2u s = m_texture.getSize();

    m_sprite.setOrigin({s.x / 2.0f, s.y / 2.0f});
    m_sprite.setPosition({screen_size.x / 8.0f, screen_size.y / 2.0f});
    m_sprite.setRotation(sf::degrees(90.0));
    m_sprite.setScale({10.0f, 10.0f});
}

void Player::update(float dt) {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) {
        m_sprite.move({0.0f, -speed * dt});
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) {
        m_sprite.move({0.0f, speed * dt});
    }
}

void Player::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    target.draw(m_sprite);
}
