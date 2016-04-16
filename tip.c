#include<head.h>

void tip_move(struct MAN man , int map[100][100])
{
    const int x[4]=[0,1,0,-1];
    const int y[4]=[1,0,-1,0];
    if (map[man->x][man->y]==MONSTER)
    {
        printf("你被怪兽吃了\n");
        man->lifestyle=1;
        return ;
    }
    if (map[man->x][man->y]==TRAP)
    {

        printf("你踩进陷阱了\n");
        man->lifestyle=2;
        return;
    }


    printf("您的当前位置：（%d,%d)\n您的金币数：%d \n",man->x,man->y,man->moneycount);
    switch ( man->faceto )
    {

        case 'e' : printf("您的朝向：东\n");break;
        case 's' : printf("您的朝向：南\n");break;
        case 'w' : printf("您的朝向：西\n");break;
        case 'n' : printf("您的朝向：北\n");break;
    }

    if (map[man->x][man->y]==MONEY)
    {

        printf("您捡到钱了\n");
        man->moneycount += 1000;
        return;
    }

    int i;
    for (i=0;i<4;i++)
    {
        switch(map[man->x+x[i]][man->y+y[i]])
        {

            case MONSTER : printf("您闻到了气味\n");break;
            case TRAP : printf("您感受到了微风\n");break;
        }
    }
    return ;

}
int tip_shoot(struct MAN man ,int map[100][100])
{
    const int x[4]=[1,0,-1,0];
    const int y[4]=[0,-1,0,1];
    int flag=0;
    switch(man->faceto)
    {
        case 'e' : if(map[man->x+x[0]][man->y+y[0]]==MONSTER) {printf("您杀死了怪物\n");flag=1;}
                    else
                    {

                        int i ;
                        for(i=man->x;map[i][man->y]!=WALL;i++) if(map[i][man->y]==MONSTER) break;
                        if(map[i][man->y]==WALL) printf("您的箭射到了墙上，并发出了咚的一声\n");
                    }
                    break;
        case 's' : if(map[man->x+x[1]][man->y+y[1]]==MONSTER) {printf("您杀死了怪物\n");flag=1;}
                    else
                    {

                        int i ;
                        for(i=man->y;map[man->x][i]!=WALL;i--) if(map[man->x][i]==MONSTER) break;
                        if(map[man->x][i]==WALL) printf("您的箭射到了墙上，并发出了咚的一声\n");
                    }
                    break;
         case 'w' : if(map[man->x+x[2]][man->y+y[2]]==MONSTER) {printf("您杀死了怪物\n");flag=1;}
                    else
                    {

                        int i ;
                        for(i=man->x;map[i][man->y]!=WALL;i--) if(map[i][man->y]==MONSTER) break;
                        if(map[i][man->y]==WALL) printf("您的箭射到了墙上，并发出了咚的一声\n");
                    }
                    break;
        case 'n' : if(map[man->x+x[3]][man->y+y[3]]==MONSTER) {printf("您杀死了怪物\n");flag=1;}
                    else
                    {

                        int i ;
                        for(i=man->y;map[man->x][i]!=WALL;i++) if(map[man->x][i]==MONSTER) break;
                        if(map[man->x][i]==WALL) printf("您的箭射到了墙上，并发出了咚的一声\n");
                    }
                    break;
    }
    return flag;

}
