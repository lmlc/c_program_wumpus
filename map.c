#include"head.h"
#include<time.h>



void printmap(int m_map[100][100],struct MAN *player){
    int x;
    int y;
    for (x=0; x < 100; x++) {
        for (y=0; y < 100; y++) {
            if (m_map[x][y]== WALL) printf("&");
            else if(m_map[x][y]==BEENROAD&&(x!=player->x||y!=player->y)) printf("1");
            else if(x==player->x&&y==player->y) printf("2");
            else if(m_map[x][y]!=-1)printf("0");
            else x=x;//这里要怎么处理 help!!
        }
        printf("\n");
    }
}//显示 墙壁&，走过的路1，主角所在的位置2，其余各种都用0

void allocate(int m_map[100][100],int monsters,int traps,int money,int weith,int height){
    int x,y,k;
    
    for(x=0,y=0;y<height;y++) m_map[x][y]=WALL;
    for(x=0,y=height-1;x<weith;x++) m_map[x][y]=WALL;
    for(x=weith-1,y=height-1;y>=0;y--) m_map[x][y]=WALL;
    for(x=weith-1,y=0;x>=0;x--) m_map[x][y]=WALL;
    
    for(x=1;x<weith-1;x++)
        for (y=1; y<height-1; y++) {
            m_map[x][y]=UNROAD;
        }
    for(x=0;x<100;x++)
        for (u=0; y<100; y++) {
            if(m_map[x][y]!=UNROAD&&m_map[x][y]!=WALL)
                m_map[x][y] = -1;
        }
    //分配墙壁与路 -1为墙以外的空间
    
    srand((unsigned) time(NULL));
    
    for(k=monsters;k>=0;){
        x = rand() % (weith-2) + 1;
        y = rand() % (height-2) + 1;
        if(m_map[x][y]==UNROAD){
            k--;
            m_map[x][y]=MONSTER;}
    }
    for(k=traps;k>=0;){
        x = rand() % 99 + 1;
        y = rand() % 99 + 1;
        if(m_map[x][y]==UNROAD){
            k--;
            m_map[x][y]=TRAP;}
    }
    for(k=money;k>=0;){
        x = rand() % 99 + 1;
        y = rand() % 99 + 1;
        if(m_map[x][y]==UNROAD){
            k--;
            m_map[x][y]=MONEY;}
    }
}


void creatmap(int m_map[100][100],int condition,int monsters,int traps,int money){
    
    int weith = 10;
    int height = 8;
    
    switch (condition) {
        case 1:
            monsters = 1;
            traps = 1;
            money = 5;
            allocate(m_map,monsters,traps,money,weith,height);
            break;
        case 2:
            monsters = 2;
            traps = 2;
            money = 6;
            allocate(m_map,monsters,traps,money,weith,height);
            break;
        case 3:
            monsters = 3;
            traps = 3;
            money = 8;
            allocate(m_map,monsters,traps,money,weith,height);
            break;
        case 4:
            allocate(m_map,monsters,traps,money,weith,height);
            break;
        default:
            break;
    }
    printmap(m_map,&man);
}








