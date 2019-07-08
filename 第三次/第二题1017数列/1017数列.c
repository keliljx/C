#include<stdio.h>
#include<malloc.h>
int main()
{
    int k,m,i,j,sum;
    scanf("%d%d",&k,&m);
/*定义动态数组*/
    int *a;
    a=(int *)malloc(sizeof(int)*m);
/*k阶斐波那契数列初始化：第K项为1，第K-1项为1，其余项为0*/
    for(i=0; i<k-1; i++)
    {
        a[i]=0;
    }
    a[k-1]=1;
    a[k]=1;
/*计算第m项对应的值*/
    for(i=k+1; i<=m; i++)/*需要从第K+1项算到第m项*/
    {
        sum=0;
        for(j=i-k; j<i; j++)/*每一项i是从前i-k项加到第i-1项，即i的前k项相加为i*/
        {
            sum=sum+a[j];
        }
        a[i]=sum;
    }
    printf("%d\n",a[m]);
}
