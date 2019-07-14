#ifndef GHOST_DIE_H
#define GHOST_DIE_H


class ghost_die
{
public:
    ghost_die(int x,int y);
    void reduce();
    int x;
    int y;
    int hp;
};

#endif // GHOST_DIE_H
