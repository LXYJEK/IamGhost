#include "hat_ghost.h"

hat_ghost::hat_ghost(int i,int j)
{
    line=i;
    col=j;
    x=line*140-45;
    y=col*170-10;
    attack_judge=0;
    hp=90;
    v=2;
}
