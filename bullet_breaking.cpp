#include "bullet_breaking.h"

bullet_breaking::bullet_breaking(int i,int j)
{
    x=i;
    y=j;
    hp=5;
}

void bullet_breaking::reduce()
{
    hp--;
}
