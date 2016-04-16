
#ifndef HEAD_H
#define HEAD_H

struct MAN{
    int x;
    int y;
    int moneycount;
    int lifestyle;//(2:die without money) (1:killed by monster)(0:lived)
};

#define UNROAD 0;
#define BEENROAD 1;
#define MONEY 3;
#define WALL 4;
#define TRAP 5;
#endif
