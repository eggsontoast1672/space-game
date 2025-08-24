#ifndef ENEMYSPAWNER_H
#define ENEMYSPAWNER_H

#include <list>

#include "enemy.h"

class EnemySpawner {
public:
    EnemySpawner();

    void update();

private:
    static constexpr float time_between_spawns = 2.6f;

    std::list<Enemy> m_enemies;
    float m_last_spawn_time;
};

#endif
