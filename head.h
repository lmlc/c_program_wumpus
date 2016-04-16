
#ifndef HEAD_H
#define HEAD_H

struct MAN{
    int x;
    int y;
    int moneycount;
    int lifestyle;//(3:killed by thorn)(2:die without money) (1:killed by monster)(0:lived)
    int direction;//(0:up)(1:right)(2:down)(3:left)
};

#define UNROAD 0;
#define BEENROAD 1;
#define MONEY 3;
#define WALL 4;
#define TRAP 5;
#endif
