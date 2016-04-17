#include <head.h>

int move(int map[1000][1000], struct MAN *player)   //返回1代表赢了，返回0代表输了
{
        char ch;
        int winorlose = 0;
        printmap (player, map);
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
                        player->faceto=0;
                        player->moneycount-=1;
                        printmap (player, map);
                        tip_move(player, map);
                }
                else if (ch=='s')
                {
                        play->faceto=1;
                        player->moneycount-=1;
                        printmap (player, map);
                        tip_move(player, map);
                }
                else if (ch=='s')
                {
                        player->faceto=2;
                        player->moneycount-=1;
                        printmap (player, map);
                        tip_move(player, map);
                }
                else if (ch=='d')
                {
                        player->faceto=3;
                        player->moneycount-=1;
                        printmap (player, map);
                        tip_move(player, map);
                }
                else if (ch==' ')                  //射箭
                {
                        if (player->moneycount>=10)
                        {
                                player->moneycount-=10;
                                if (tip_shoot(player, map)==1)    //tip_shoot函数返回了1代表怪物死了
                                        return 1;
                        }
                        else
                        {
                                printf ("你的钱不够买弓箭！");
                        }
                }
                else if (ch=='q')      //前进
                {
                        if (player->faceto==0)
                        {
                                player->y--;
                        }
                        else if (player->faceto==1)
                        {
                                player->x++;
                        }
                        else if (player->faceto==2)
                        {
                                player->y++;
                        }
                        else if (player->faceto==3)
                        {
                                player->x--;
                        }
                        player->moneycount-=1;
                        tip_move(player, map);
                        map[player->x][player->y]==BEENLOAD;    //走过的路
                        if (player->lifestyle!=0)
                        {
                                return 0;
                        }
                }
        }
}
