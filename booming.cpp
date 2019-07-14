#include "booming.h"

booming::booming(int i,int j)
{
    x=i;
    y=j;
    hp=10;
}

void booming::reduce()
{
    hp--;
}
