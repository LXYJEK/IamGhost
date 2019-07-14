#include "ghost_die.h"

ghost_die::ghost_die(int i,int j)
{
    x=i;
    y=j;
    hp=15;
}

void ghost_die::reduce()
{
    hp--;
}
