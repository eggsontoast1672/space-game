#include "player.h"

#include "bullet.h"
#include "globals.h"

Player::Player() {
    gameObjects.push_back(this);

    Image playerImage = LoadImage(ASSET_PATH "ship.png");
    ImageRotateCW(&playerImage);
    texture = LoadTextureFromImage(playerImage);
    texture.height *= 10;
    texture.width *= 10;

    position = {(float)GetScreenWidth() / 8, (float)GetScreenHeight() / 2};

    speed = -325;

    timeBetweenShots = 0.45f;
    lastShotTime = (float)GetTime() - timeBetweenShots;

    score = 0;

    shotSound = LoadSound(ASSET_PATH "shootSFX.mp3");
}

void Player::Update() {
    if ((IsKeyDown(KEY_W) || IsKeyDown(KEY_UP)) && position.y > 64) {
        position.y += speed * GetFrameTime();
    } else if ((IsKeyDown(KEY_S) || IsKeyDown(KEY_DOWN)) &&
               position.y < GetScreenHeight() - 64) {
        position.y -= speed * GetFrameTime();
    }

    if (IsKeyPressed(KEY_SPACE) &&
        lastShotTime + timeBetweenShots <= (float)GetTime()) {
        new Bullet(position);

        PlaySound(shotSound);

        lastShotTime = (float)GetTime();
    }
}

void Player::Render() {
    DrawTexture(texture, position.x - texture.width / 2,
                position.y - texture.height / 2, WHITE);
}

Player::~Player() {
    UnloadTexture(texture);
    UnloadSound(shotSound);
}
