#include<stdio.h>
#include<conio.h>
void menu()
{
    printf("1.��ʼ��Ϸ��\n 2.���а�\n 3.����\n");
    char ch=_getch();
    switch(ch)
    {

        case '1':start();break;
        case '2':paihangbang_r();break;
        case '3':help();break;
    }
}
void help()
{

    printf("����һ��ʼλ�������С����\n");
    printf("ÿ��С��������ǿյģ�Ҳ���������塢���޻���\n");
    printf("�������ڵķ�����ϡ��¡������ĸ����ڵķ�������΢��\n");
    printf("�������ڵķ�����ϡ��¡������ĸ����ڵķ���������ζ\n");
    printf("���޲����ƶ�\n");
    printf("������λ��ĳ���ո�ʱ����ý�һ����ŵ���ζ���߸��ܵ�΢��\n");
    printf("�������ϴ���һ�������Ľ�ң�����ÿ�ƶ�һ������Ҫ����1���\n");
    printf("����ǰ��ʱ�����ǰ����ǽ�ڣ����������ʧ�ܣ�����ö���ʧ�ܵ�֪ͨ������һ�ζ���\n");
    printf("���ǿ�����ǰ�������ÿ���������Ҫ����10���\n");
    printf("�������ʱ��ǰ�������һ�����ޱ����������޻ᷢ���ҽ��������ǰ��������û�й��ޣ����ǿ���������ͷײ��ǽ�ڷ���������\n");
    printf("������������й��޻�����ķ�����������������������Ϸ����\n");
    printf("��Ϸ��Ŀ���ǻ�õ�ͼ�ϵ����н�ң�������������ǰ��þ����ܶ�Ľ��\n");

}
void start(int m_map[100][100],struct MAN *man)
{
    printf("ѡ��ģʽ��1.�򵥣�2.�еȣ�3.�ѣ�4.�Զ���");
    char ch =_getch();
    switch(ch)
    {

        case '1' : map(m_map,1,0,0,0);break;
        case '2':  map(m_map,2,0,0,0);break;
        case '3':  map(m_map,3,0,0,0):break;
        case '4': int i,j,k;printf("����������������������ͽ��������\n");
                    scanf("%d%d%d",&i,&j,&k);
                    getchar();
                    map(m_map,4,i,j,k);break;
    }
     if(move(m_map,man)==1)
     {printf("��Ӯ��\n");
     printf("��������������\n");
     char num[20];
     scanf("%s",num);
     paihangbang_w(man->moneycount,num);}
     else printf("������\n")��
    return ;

}
