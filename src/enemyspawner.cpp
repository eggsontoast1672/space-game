#include "enemyspawner.h"

#include "raylib.h"

EnemySpawner::EnemySpawner() {
    m_last_spawn_time = GetTime() - time_between_spawns;
}

void EnemySpawner::update() {
    double time = GetTime();
    if (m_last_spawn_time + time_between_spawns <= time) {
        m_enemies.emplace_back();
        m_last_spawn_time = time;
    }
}
