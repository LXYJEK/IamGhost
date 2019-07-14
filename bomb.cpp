#include "bomb.h"

bomb::bomb(int i,int j)
{
    line=i;
    col=j;
    x=line*145-85;
    y=col*170-10;
    hp=1;
    power=100000;
}

booming* bomb::attack(ghost *ghostc)
{
    booming* boomingc;
    boomingc=new booming(x,y);
    hp-=power;
    return boomingc;
}
