#include<stdio.h>
#include<malloc.h>
int main()
{
    int k,m,i,j,sum;
    scanf("%d%d",&k,&m);
/*���嶯̬����*/
    int *a;
    a=(int *)malloc(sizeof(int)*m);
/*k��쳲��������г�ʼ������K��Ϊ1����K-1��Ϊ1��������Ϊ0*/
    for(i=0; i<k-1; i++)
    {
        a[i]=0;
    }
    a[k-1]=1;
    a[k]=1;
/*�����m���Ӧ��ֵ*/
    for(i=k+1; i<=m; i++)/*��Ҫ�ӵ�K+1���㵽��m��*/
    {
        sum=0;
        for(j=i-k; j<i; j++)/*ÿһ��i�Ǵ�ǰi-k��ӵ���i-1���i��ǰk�����Ϊi*/
        {
            sum=sum+a[j];
        }
        a[i]=sum;
    }
    printf("%d\n",a[m]);
}
