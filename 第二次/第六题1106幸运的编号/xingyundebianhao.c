/*
幸运的编号
描述：
有n个人围成一圈，顺序编号。从第一个人开始报数（从1到m），
凡报到m的人退出。问最后一个人的编号是多少？
输入：输入两个正整数n和m
输出：最后一个人的编号。
输入样例：5 2
输出样例：3
*/
#include <stdio.h>
#include<malloc.h>
int main()
{
    int n,m,i;
    scanf("%d%d",&n,&m);
    int *a;
    a = (int*)malloc(sizeof(int)*n);
    for(i=0; i<n; i++) //给每个人赋初始值
    {
        a[i]=i+1;
    }
    int count=0;//退出的人的数目
    int sum=0;//报数
    while(count<n-1)/*一直报数到退出的人数为n-1
                    注意是n-1而不是n  计数到n-1才跳出循环*/

    {
        for(i=0; i<n; i++) //从1报数报到m 再一直循环
        {
            if(a[i]!=0)//设值为0的时候表示已退出，判断此人是否退出
            {
                sum=sum+1;//若没退出，报数
            }
            if(sum==m)//如果报到了m
            {
                a[i]=0;//报到m的人退出
                count++;
                sum=0;//报数清零
            }
        }
    }
    for(i=0; i<n; i++)//找到最后剩的人
    {
        if(a[i]>0)
        {
            printf("%d\n",a[i]);
        }
    }
    return 0;
}
