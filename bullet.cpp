#include "bullet.h"

bullet::bullet(int i,int j)
{
    line=i;
    col=j;
    x=line*145-85;
    y=col*170-10;
    v=15;
    hp=1;
    power=5;
}

void bullet::move()
{
    x+=v;
    line=(x+129)/172+1;
}

bullet_breaking* bullet::attack(ghost *ghostc)
{
    bullet_breaking* bullet_breakingc;
    bullet_breakingc=new bullet_breaking(x,y);
    ghostc->hp-=power;
    hp-=power;
    return bullet_breakingc;
}
