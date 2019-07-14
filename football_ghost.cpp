#include "football_ghost.h"

football_ghost::football_ghost(int i,int j)
{
    line=i;
    col=j;
    x=line*140-45;
    y=col*170-10;
    attack_judge=0;
    hp=200;
    v=4;
}
