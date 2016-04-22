#include "engine.h"
#include "function.h"

void help()
{

    printf("主角一开始位于随机的小方块\n");
    printf("每个小方格可能是空的，也可能有陷阱、怪兽或金币\n");
    printf("陷阱所在的方格和上、下、左、右四个相邻的方格内有微风\n");
    printf("怪兽所在的方格和上、下、左、右四个相邻的方格内有异味\n");
    printf("怪兽不会移动\n");
    printf("当主角位于某个空格时，获得金币或者闻到气味或者感受到微风\n");
    printf("主角身上带有一定数量的金币，主角每移动一步都需要消耗1金币\n");
    printf("主角前进时，如果前方是墙壁，则这个动作失败，但获得动作失败的通知并消耗一次动作\n");
    printf("主角可以向前方射箭，每次射箭都需要消耗10金币\n");
    printf("主角射箭时，前方最近的一个怪兽被射死，怪兽会发出惨叫声；如果前进方向上没有怪兽，主角可以听到箭头撞击墙壁发出的声音\n");
    printf("主角如果进入有怪兽或陷阱的方格，主角立即死亡并结算游戏分数\n");
    printf("游戏的目的是获得地图上的所有金币，或在主角死亡前获得尽可能多的金币\n");

}
void start(int m_map[100][100],struct MAN *player)
{
    printf("选择模式：1.简单；2.中等；3.难；4.自定义\n");
    char ch =_getch();
    int i,j,k;
    switch(ch)
    {

        case '1':  creatmap(m_map,1,0,0,0,player);break;
        case '2':  creatmap(m_map,2,0,0,0,player);break;
        case '3':  creatmap(m_map,3,0,0,0,player);break;
        case '4':
            printf("输入怪物数量，陷阱数量和金币数量：\n");
            scanf("%d%d%d",&i,&j,&k);
            getchar();
            creatmap(m_map,4,i,j,k,player);
            break;
    }
    if(move(m_map,player)==1)
    {   printf("您赢了\n");
        printf("请输入您的名字\n");
        char num[20];
        scanf("%s",num);
        paihangbang_w(player->moneycount,num);}
    else printf("您输了\n");
    return ;
}
