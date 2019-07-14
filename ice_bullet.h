#ifndef ICE_BULLET_H
#define ICE_BULLET_H
#include "ghost.h"
#include "ice_bullet_breaking.h"

class ice_bullet
{
public:
    ice_bullet(int i,int j);
    ice_bullet_breaking* attack(ghost* ghostc);
    void move();
    int line,col;
    int x;
    int y;
    float v;
    int hp;
    int power;
};

#endif // ICE_BULLET_H
