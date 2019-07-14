#ifndef ICE_SHOOTER_H
#define ICE_SHOOTER_H
#include "plant.h"
#include "ice_bullet.h"


class ice_shooter:public plant
{
public:
    ice_shooter(int i,int j);
    int timer();
    ice_bullet* shoot_ice_bullet();
    int shooter_timer;
};

#endif // ICE_SHOOTER_H
