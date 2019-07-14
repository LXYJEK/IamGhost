#ifndef GHOST_H
#define GHOST_H
#include "plant.h"
#include "ghost_die.h"

class ghost
{
public:
    ghost();
    void move();
    void ice();
    void attack(plant* plantc);
    ghost_die* die();
    int line,col;
    int x;
    int y;
    float v;
    int attack_judge;
    int ice_judge;
    int hp;
    int power;
};

#endif // GHOST_H
