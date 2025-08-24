#include "background.h"

#include "globals.h"

Background::Background() {
    gameObjects.push_back(this);

    Image backgroundImage = LoadImage(ASSET_PATH "background.png");
    texture = LoadTextureFromImage(backgroundImage);
    SetTextureFilter(texture, FILTER_POINT);
}

void Background::Update() {}

void Background::Render() {
    Rectangle source = {(float)GetScreenWidth() / 2,
                        (float)GetScreenWidth() / 2 - texture.width,
                        (float)GetScreenHeight() / 2,
                        (float)GetScreenHeight() / 2 - texture.height};
    Rectangle destination = {0, 0, (float)GetScreenWidth() * 2,
                             (float)GetScreenHeight() * 2};
    DrawTextureTiled(
        texture, source, destination,
        {(float)GetScreenWidth() / 2, (float)GetScreenHeight() / 2}, 0, 10,
        WHITE);
}

Background::~Background() { UnloadTexture(texture); }
