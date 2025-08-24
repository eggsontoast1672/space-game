#ifndef ENEMYSPAWNER_H
#define ENEMYSPAWNER_H

#include <list>

#include "gameobject.h"

class EnemySpawner : public GameObject {
public:
    EnemySpawner();
    virtual void Update();
    virtual void Render();
    ~EnemySpawner(void);

private:
    std::list<GameObject *> enemies;
    void Spawn();
    float timeAtLastSpawn;
    float timeBetweenSpawns;
};

#endif
