#include "background.h"

Background::Background() {
    m_texture = LoadTexture(ASSET_PATH "background.png");

    m_source = Rectangle{
        0.0f,
        0.0f,
        static_cast<float>(m_texture.width),
        static_cast<float>(m_texture.height),
    };

    m_dest = Rectangle{
        0.0f,
        0.0f,
        static_cast<float>(GetScreenWidth()),
        static_cast<float>(GetScreenHeight()),
    };
}

void Background::render() const {
    Vector2 origin{0, 0};
    DrawTexturePro(m_texture, m_source, m_dest, origin, 0, WHITE);
}

Background::~Background() { UnloadTexture(m_texture); }
