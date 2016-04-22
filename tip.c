#include "engine.h"
#include "function.h"
void tip_move(int map[100][100],struct MAN *player)
{
    const int x[4]={0,1,0,-1};
    const int y[4]={1,0,-1,0};
    if (map[player->x][player->y]==MONSTER)
    {
        printf("你被怪兽吃了\n");
        player->lifestyle=1;
        return ;
    }
    if (map[player->x][player->y]==TRAP)
    {

        printf("你踩进陷阱了\n");
        player->lifestyle=2;
        return;
    }


    printf("您的当前位置：（%d,%d)\n您的金币数：%d \n",player->x,player->y,player->moneycount);
    switch ( player->faceto )
    {

        case 'e' : printf("您的朝向：东\n");break;
        case 's' : printf("您的朝向：南\n");break;
        case 'w' : printf("您的朝向：西\n");break;
        case 'n' : printf("您的朝向：北\n");break;
    }

    if (map[player->x][player->y]==MONEY)
    {

        printf("您捡到钱了\n");
        player->moneycount += 1000;
        return;
    }

    int i;
    for (i=0;i<4;i++)
    {
        switch(map[player->x+x[i]][player->y+y[i]])
        {

            case MONSTER : printf("您闻到了气味\n");break;
            case TRAP : printf("您感受到了微风\n");break;
        }
    }
    return ;

}
int tip_shoot(int map[100][100],struct MAN *player)
{
    int flag=0;
    switch(player->faceto)
    {
        case 0 :
        {int i ;
            for(i=player->x;map[i][player->y]!=WALL;i++)
                if(map[i][player->y]==MONSTER) {map[i][player->y]=UNROAD;printf("您杀死了怪物\n");flag=1;break;}
            if(map[i][player->y]==WALL) printf("您的箭射到了墙上，并发出了咚的一声\n");
            break;}
        case 1 :
        {int i ;
            for(i=player->y;map[player->x][i]!=WALL;i--)
                if(map[player->x][i]==MONSTER) {map[player->x][i]=UNROAD;printf("您杀死了怪物\n");flag=1;break;}
            if(map[player->x][i]==WALL) printf("您的箭射到了墙上，并发出了咚的一声\n");
            break;}
        case 2 :
        {int i ;
            for(i=player->x;map[i][player->y]!=WALL;i--)
                if(map[i][player->y]==MONSTER){map[i][player->y]=UNROAD;printf("您杀死了怪物\n");flag=1;break;}
            if(map[i][player->y]==WALL) printf("您的箭射到了墙上，并发出了咚的一声\n");
            break;}
        case 3 :
        {int i ;
            for(i=player->y;map[player->x][i]!=WALL;i++)
                if(map[player->x][i]==MONSTER) {map[player->x][i]=UNROAD;printf("您杀死了怪物\n");flag=1;break;}
            if(map[player->x][i]==WALL) printf("您的箭射到了墙上，并发出了咚的一声\n");
            break;}
    }
    return flag;
}
