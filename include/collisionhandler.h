#ifndef COLLISION_HANDLER_H
#define COLLISION_HANDLER_H

#include "gameobject.h"

class CollisionHandler : public GameObject {
public:
    CollisionHandler(void);
    virtual void Update();
    virtual void Render();
    ~CollisionHandler(void);
};

#endif
