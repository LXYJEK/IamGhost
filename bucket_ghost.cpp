#include "bucket_ghost.h"

bucket_ghost::bucket_ghost(int i,int j)
{
    line=i;
    col=j;
    x=line*140-45;
    y=col*170-10;
    attack_judge=0;
    hp=190;
    v=2;
}
