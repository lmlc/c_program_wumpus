
void paihangbang_r()
{

    FILE *fp=fopen("paihangbang.txt","r+");
    struct PERSON{char a[20];int money;}person[10];
    int i;
    for(i=0;i<10;i++)
    {

        fscanf(fp,"%s%d",person[i].a,&person[i].money);
    }
    fclose(fp);
    for(i=0;i<10;i++)
    {

        printf("%s %d\n",person[i].a,person[i].money);
    }
}

void paihangbang_w(int money, char name[])
{
    char num[20];
    FILE *fp=fopen("paihangbang.txt","r");
    struct PERSON{char a[20];int money;}person[200];
    int i=0;
    while(!feof(fp))
    {
      fscanf(fp,"%s%d",person[i].a,&person[i].money);
      i++;
    }
    int total = i;
    fclose(fp);
    for(i=0;i<total;i++)
    {

        if(person[i].money<=money) break;
    }
    int j;
    for(j=total;j>i;j--)
    {

        person[j]=person[j-1];
    }
    scanf("%s",num);
    strcpy(person[i].a,num);
    person[i].money=money;
    printf("您的排名为:%d\n", i+1);
    FILE *fp1=fopen("paihangbang.txt","w");
    for(i=0;i<=total;i++)
    {

        fprintf(fp1,"%s %d",person[i].a,person[i].money);
    }
    fclose(fp1);


}

