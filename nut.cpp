#include "nut.h"

nut::nut(int i,int j)
{
    line=i;
    col=j;
    x=line*145-85;
    y=col*170-10;
    hp=5000;
}
