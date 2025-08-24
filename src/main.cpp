#include "background.h"
#include "collisionhandler.h"
#include "enemyspawner.h"
#include "gameobject.h"
#include "globals.h"
#include "musicplayer.h"
#include "player.h"
#include "raylib.h"
#include "scoredisplay.h"

int main(void) {
    InitWindow(1920, 1080, "C++ Game");

    Background background;
    CollisionHandler handler;
    Player player;
    EnemySpawner spawner;
    MusicPlayer musicPlayer;
    ScoreDisplay display;

    while (!WindowShouldClose()) {
        for (GameObject *gameObject : gameObjects) {
            gameObject->Update();
        }

        BeginDrawing();

        ClearBackground(WHITE);

        background.render();

        for (GameObject *gameObject : gameObjects) {
            gameObject->Render();
        }

        EndDrawing();
    }

    CloseWindow();

    return 0;
}
