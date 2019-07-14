#ifndef BULLET_H
#define BULLET_H
#include "ghost.h"
#include "bullet_breaking.h"


class bullet
{
public:
    bullet(int i,int j);
    bullet_breaking* attack(ghost* ghostc);
    void move();
    int line,col;
    int x;
    int y;
    float v;
    int hp;
    int power;
};

#endif // BULLET_H
