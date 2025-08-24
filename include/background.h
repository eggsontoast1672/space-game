#ifndef BACKGROUND_H
#define BACKGROUND_H

#include "raylib.h"

class Background {
public:
    Background();
    Background(const Background &) = delete;
    Background &operator=(const Background &) = delete;
    Background(Background &&) = delete;
    Background &operator=(Background &&) = delete;
    ~Background();

    void render() const;

private:
    Texture m_texture;
    Rectangle m_source;
    Rectangle m_dest;
};

#endif
