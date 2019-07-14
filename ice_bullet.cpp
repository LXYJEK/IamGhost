#include "ice_bullet.h"

ice_bullet::ice_bullet(int i,int j)
{
    line=i;
    col=j;
    x=line*145-85;
    y=col*170-10;
    v=15;
    hp=1;
    power=5;
}

void ice_bullet::move()
{
    x+=v;
    line=(x+129)/172+1;
}

ice_bullet_breaking* ice_bullet::attack(ghost *ghostc)
{
    ice_bullet_breaking* ice_bullet_breakingc;
    ice_bullet_breakingc=new ice_bullet_breaking(x,y);
    ghostc->hp-=power;
    ghostc->ice();
    hp-=power;
    return ice_bullet_breakingc;
}
