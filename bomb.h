#ifndef BOMB_H
#define BOMB_H
#include "plant.h"
#include "ghost.h"
#include "booming.h"


class bomb:public plant
{
public:
    bomb(int i,int j);
    booming* attack(ghost* ghostc);
    int power;
};

#endif // BOMB_H
