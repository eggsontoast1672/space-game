#include "enemy.h"

Enemy::Enemy() {
    gameObjects.push_back(this);
    enemyCollisionObjects.push_back(this);

    id = GetRandomValue(0, 2);

    switch (id) {
    case 0: {
        Image enemyImageOne = LoadImage(ASSET_PATH "enemy1.png");
        ImageRotateCW(&enemyImageOne);
        texture = LoadTextureFromImage(enemyImageOne);
        texture.height *= 10;
        texture.width *= 10;

        speed = -100;
        break;
    }
    case 1: {
        Image enemyImageTwo = LoadImage(ASSET_PATH "enemy2.png");
        ImageRotateCW(&enemyImageTwo);
        texture = LoadTextureFromImage(enemyImageTwo);
        texture.height *= 10;
        texture.width *= 10;

        speed = -150;
        break;
    }
    case 2: {
        Image enemyImageThree = LoadImage(ASSET_PATH "enemy3.png");
        ImageRotateCW(&enemyImageThree);
        texture = LoadTextureFromImage(enemyImageThree);
        texture.height *= 10;
        texture.width *= 10;

        speed = -165;
        break;
    }
    default:
        printf("Uh oh");
        break;
    }

    position.x = GetScreenWidth() + 150;
    position.y = GetRandomValue(64, GetScreenHeight() - 64);

    collisionRect.height = texture.height;
    collisionRect.width = texture.width;
    UpdateCollisionRectPosition();
}

void Enemy::Update() {
    position.x += speed * GetFrameTime();
    UpdateCollisionRectPosition();
}

void Enemy::Render() {
    DrawTexture(texture, position.x - texture.width / 2,
                position.y - texture.height / 2, WHITE);
}

inline void Enemy::UpdateCollisionRectPosition() {
    collisionRect.x = position.x - texture.width / 2;
    collisionRect.y = position.y - texture.height / 2;
}

Rectangle Enemy::GetRect() { return collisionRect; }

void Enemy::Destroy() { delete this; }

Enemy::~Enemy() {
    ++score;

    enemyCollisionObjects.erase(std::remove(enemyCollisionObjects.begin(),
                                            enemyCollisionObjects.end(), this));
    gameObjects.erase(
        std::remove(gameObjects.begin(), gameObjects.end(), this));
    UnloadTexture(texture);
}
