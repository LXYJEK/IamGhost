#ifndef SHOOTER_H
#define SHOOTER_H
#include "plant.h"
#include "bullet.h"


class shooter:public plant
{
public:
    shooter(int i,int j);
    int timer();
    bullet* shoot_bullet();
    int shooter_timer;
};

#endif // SHOOTER_H
