#include "ice_shooter.h"

ice_shooter::ice_shooter(int i,int j)
{
    line=i;
    col=j;
    x=line*145-85;
    y=col*170-10;
    hp=1500;
    shooter_timer=39;
}

ice_bullet* ice_shooter::shoot_ice_bullet()
{
    ice_bullet* ice_bulletc=new ice_bullet(line,col);
    return ice_bulletc;
}

int ice_shooter::timer()
{
    shooter_timer++;
    if(shooter_timer==40){
        shooter_timer=0;
        return 1;
    }
    else
        return 0;
}
