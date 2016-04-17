#include"head.h"

extern int monsters;

int move(int map[100][100],struct MAN *player)   //返回1代表赢了，返回0代表输了
{
        char ch;
        int winorlose = 0;
        tip_move(player, map);
        while (!kbhit())           //判断键盘有无输入
        {
                ch=getch();
                if (ch=='w')       //方向
                {
                        player->faceto=3;         //改变方向
                        player->moneycount-=1;    //扣钱
                        printmap (player, map);  //打印地图
                        tip_move(player, map);   //移动的提示
                }
                else if (ch=='a')
                {
                        player->faceto=2;
                        player->moneycount-=1;
                        printmap (player, map);
                        tip_move(player, map);
                }
            
                else if (ch=='s')
                {
                        player->faceto=1;
                        player->moneycount-=1;
                        printmap (player, map);
                        tip_move(player, map);
                }
                else if (ch=='d')
                {
                        player->faceto=0;
                        player->moneycount-=1;
                        printmap (player, map);
                        tip_move(player, map);
                }
                else if (ch==' ')                  //射箭
                {
                        if (player->moneycount>=10)
                        {
                             player->moneycount-=10;
                            if(tip_shoot(player, map)==1)//tip_shoot函数返回了1代表怪物被射死
                            {
                                monsters--;
                            }
                            if(monsters==0) return 1;//monster死光了，胜利
                        }
                        else
                        {
                                printf ("您钱不够，射不了剑!");
                        }
                }
                else if (ch=='q')      //前进
                {
                        if (player->faceto==0)
                        {
                                player->x++;
                        }
                        else if (player->faceto==1)
                        {
                                player->y++;
                        }
                        else if (player->faceto==2)
                        {
                                player->x--;
                        }
                        else if (player->faceto==3)
                        {
                                player->y--;
                        }
                        player->moneycount-=1;
                        tip_move(player, map);
                        map[player->x][player->y]==BEENLOAD;    //走过的路
                        printmap (player, map);
                        if (!player->lifestyle)//死了
                        {
                                return 0;
                        }
                }
        }
}
