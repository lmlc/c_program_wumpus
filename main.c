#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include<conio.h>
#include"engine.h"
#include"function.h"
//#include"map.c"
//#include"move.c"
//#include"menu.c"
//#include"paihangbang.c"
//#include"tip.c"
int monsters;

int main(){
    int m_map[100][100]={-1};
    struct MAN man;
    man.x=1;
    man.y=1;
    man.moneycount=100;
    man.lifestyle=0;
    man.faceto=1;
    //全局的monsters
    printf("1.开始游戏：\n 2.排行榜：\n 3.帮助\n");
    char ch=_getch();
    switch(ch)
    {

        case '1':start(m_map,&man);break;

        case '2':paihangbang_r();break;

        case '3':help();break;
    }

    return 0;
}
