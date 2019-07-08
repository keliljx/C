/*
描述：三阶幻方是最简单的幻方，又叫九宫格，
是由1,2,3,4,5,6,7,8,9九个数字组成的一个三行三列的矩阵，
其对角线、横行、纵向的的和都为15。
拆填方式 想：1+9=10，2+8=10，3+7=10，4+6=10。这每对数的和再加上5都等于15，
可确定中心格应填5，这四组数应分别填在横、竖和对角线的位置上。先填四个角，
若填两对奇数，那么因三个奇数的和才可能得奇数，四边上的格里已不可再填奇数，不行。
若四个角分别填一对偶数，一对奇数，也行不通。
因此，判定四个角上必须填两对偶数。对角线上的数填好后，其余格里再填奇数就很容易了。
*/
#include<stdio.h>
int a[3][3];
int used[10];
void search(int n);
void testout();
void output();
int main()
{
  search(0);
  return 0;
}
void search(int n)
{
    int i,j;
    if(n==9)
        testout();
    else
    {
            for (i=1;i<=9;i++)
    {
        if(used[i]==0)
            {

                a[n/3][n%3]=i;
                used[i]=1;//表示该数已经被用过，不能再一次使用
                search(n+1);
                used[i]=0;//回溯时使used[i]恢复原值
            }
    }
    }
}
void testout()
{
    int i,j,flag=1;
    for(i=0; i<3; i++)
    {
        if(a[i][0]+a[i][1]+a[i][2]!=15||a[0][i]+a[1][i]+a[2][i]!=15)
        {
            flag=0;
            break;
        }
    }
    if(flag==1)
    {
               if(a[0][0]+a[1][1]+a[2][2]!=15||a[0][2]+a[1][1]+a[2][0]!=15)
            flag=0;
    }

    if(flag==1)output();
}
void output()
{
    int i,j;
    for(i=0; i<3; i++)
    {
        for(j=0; j<3; j++)
        {
            if(j<=1)
            {
                printf("%d ",a[i][j]);
            }
            if(j==2)
            {
                printf("%d",a[i][j]);
            }
            }
            printf("\n");
    }
    printf("\n");

}


