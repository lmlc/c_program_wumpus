
#ifndef HEAD_H
#define HEAD_H

struct MAN{
    int x;
    int y;
    int moneycount;
    int lifestyle;//(3:killed by thorn)(2:die without money) (1:killed by monster)(0:lived)
    int faceto;//(0:east)(1:south)(2:west)(3:north)
};

#define UNROAD 0;
#define BEENROAD 1;
#define MONSTER 2;
#define MONEY 3;
#define WALL 4;
#define TRAP 5;
#endif
