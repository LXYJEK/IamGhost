#include "ghost.h"

ghost::ghost(){ice_judge=0;power=25;}

void ghost::move()
{
    x-=v;
    attack_judge=0;
    line=(x+85)/145+1;
    if(x<-210)
        hp=0;
}

void ghost::attack(plant* plantc)
{
    x-=0;
    attack_judge=1;
    plantc->hp-=power;
}

ghost_die* ghost::die()
{
    ghost_die* ghost_diec;
    ghost_diec=new ghost_die(x,y);
    return ghost_diec;
}

void ghost::ice()
{
    if(ice_judge==0){
        v/=2;
        power=15;
        ice_judge=1;
    }
}
