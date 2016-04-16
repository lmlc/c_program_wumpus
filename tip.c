#include<head.h>

void tip_move(struct MAN man , int map[100][100])
{
    const int x[4]=[0,1,0,-1];
    const int y[4]=[1,0,-1,0];
    if (map[man->x][man->y]==MONSTER)
    {
        printf("�㱻���޳���\n");
        man->lifestyle=1;
        return ;
    }
    if (map[man->x][man->y]==TRAP)
    {

        printf("��Ƚ�������\n");
        man->lifestyle=2;
        return;
    }


    printf("���ĵ�ǰλ�ã���%d,%d)\n���Ľ������%d \n",man->x,man->y,man->moneycount);
    switch ( man->faceto )
    {

        case 'e' : printf("���ĳ��򣺶�\n");break;
        case 's' : printf("���ĳ�����\n");break;
        case 'w' : printf("���ĳ�����\n");break;
        case 'n' : printf("���ĳ��򣺱�\n");break;
    }

    if (map[man->x][man->y]==MONEY)
    {

        printf("����Ǯ��\n");
        man->moneycount += 1000;
        return;
    }

    int i;
    for (i=0;i<4;i++)
    {
        switch(map[man->x+x[i]][man->y+y[i]])
        {

            case MONSTER : printf("���ŵ�����ζ\n");break;
            case TRAP : printf("�����ܵ���΢��\n");break;
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
        case 'e' : if(map[man->x+x[0]][man->y+y[0]]==MONSTER) {printf("��ɱ���˹���\n");flag=1;}
                    else
                    {

                        int i ;
                        for(i=man->x;map[i][man->y]!=WALL;i++) if(map[i][man->y]==MONSTER) break;
                        if(map[i][man->y]==WALL) printf("���ļ��䵽��ǽ�ϣ����������˵�һ��\n");
                    }
                    break;
        case 's' : if(map[man->x+x[1]][man->y+y[1]]==MONSTER) {printf("��ɱ���˹���\n");flag=1;}
                    else
                    {

                        int i ;
                        for(i=man->y;map[man->x][i]!=WALL;i--) if(map[man->x][i]==MONSTER) break;
                        if(map[man->x][i]==WALL) printf("���ļ��䵽��ǽ�ϣ����������˵�һ��\n");
                    }
                    break;
         case 'w' : if(map[man->x+x[2]][man->y+y[2]]==MONSTER) {printf("��ɱ���˹���\n");flag=1;}
                    else
                    {

                        int i ;
                        for(i=man->x;map[i][man->y]!=WALL;i--) if(map[i][man->y]==MONSTER) break;
                        if(map[i][man->y]==WALL) printf("���ļ��䵽��ǽ�ϣ����������˵�һ��\n");
                    }
                    break;
        case 'n' : if(map[man->x+x[3]][man->y+y[3]]==MONSTER) {printf("��ɱ���˹���\n");flag=1;}
                    else
                    {

                        int i ;
                        for(i=man->y;map[man->x][i]!=WALL;i++) if(map[man->x][i]==MONSTER) break;
                        if(map[man->x][i]==WALL) printf("���ļ��䵽��ǽ�ϣ����������˵�һ��\n");
                    }
                    break;
    }
    return flag;

}
