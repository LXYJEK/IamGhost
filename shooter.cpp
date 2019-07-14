#include "shooter.h"

shooter::shooter(int i,int j)
{
    line=i;
    col=j;
    x=line*145-85;
    y=col*170-10;
    hp=1500;
    shooter_timer=39;
}

bullet* shooter::shoot_bullet()
{
    bullet* bulletc=new bullet(line,col);
    return bulletc;
}

int shooter::timer()
{
    shooter_timer++;
    if(shooter_timer==40){
        shooter_timer=0;
        return 1;
    }
    else
        return 0;
}
