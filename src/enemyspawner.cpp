#include "enemyspawner.h"

#include "enemy.h"
#include "globals.h"
#include "raylib.h"

EnemySpawner::EnemySpawner() {
    gameObjects.push_back(this);

    timeBetweenSpawns = 2.6f;
    timeAtLastSpawn = GetTime() - timeBetweenSpawns;
}

void EnemySpawner::Update() {
    if (timeAtLastSpawn + timeBetweenSpawns <= (float)GetTime()) {
        Spawn();

        timeAtLastSpawn = (float)GetTime();
    }
}

void EnemySpawner::Render() {}

EnemySpawner::~EnemySpawner() { enemies.clear(); }

void EnemySpawner::Spawn() {
    Enemy *enemy = new Enemy();
    enemies.push_back(enemy);
}
