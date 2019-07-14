#include "ice_bullet_breaking.h"

ice_bullet_breaking::ice_bullet_breaking(int i,int j)
{
    x=i;
    y=j;
    hp=5;
}

void ice_bullet_breaking::reduce()
{
    hp--;
}
