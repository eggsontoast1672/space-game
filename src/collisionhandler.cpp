#include "collisionhandler.h"

CollisionHandler::CollisionHandler() { gameObjects.push_back(this); }

void CollisionHandler::Update() {
    for (Bullet *&bullet : bulletCollisionObjects) {
        for (Enemy *&enemy : enemyCollisionObjects) {
            bool collided =
                CheckCollisionRecs(bullet->GetRect(), enemy->GetRect());
            if (collided) {
                bullet->Destroy();
                enemy->Destroy();
            }
        }
    }
}

void CollisionHandler::Render() {}

CollisionHandler::~CollisionHandler() {}
