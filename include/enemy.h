#ifndef ENEMY_H
#define ENEMY_H

#include "collisionobjects.h"
#include "globals.h"
#include "player.h"
#include "raylib.h"
#include <algorithm>

class Enemy : public GameObject {
public:
    Enemy();
    virtual void Update();
    virtual void Render();
    virtual ~Enemy(void);

    void Destroy();
    Rectangle GetRect();

private:
    void UpdateCollisionRectPosition();

    int id;

    Texture texture;
    Vector2 position;
    float speed;

    Rectangle collisionRect;
};

#endif
