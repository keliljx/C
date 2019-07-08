#include<stdio.h>
#define MAX 100
int a[MAX][MAX];
int main()
{
	int i,j;
int n,z,c,flag=0,num=1;
scanf("%d",&n);
for(z=0,c=1;z<2*n-1;z++)//总的循环次数
{//左上部分的循环
if(z<n-1)
{
if(flag==0)//斜上开始
{
for(i=0;i<c;i++)
a[i][z-i]=num++;
flag=1;
}
else//斜下
{
for(i=0;i<c;i++)
a[z-i][i]=num++;
flag=0;
}
++c;
}
else//右下部分
{
if(flag==0)
{
for(i=n-1,j=0;j<c;i--,++j)
{
a[z-i][i]=num++;
flag=1;
}
}
else
{
for(i=n-1,j=0;j<c;i--,++j)
{
a[i][z-i]=num++;
flag=0;
}
}--c;
}
}
//打印方阵
for(i=0;i<n;++i)
{
for(j=0;j<n;++j)
{
printf("%4d",a[i][j]);
}
printf("\n\n");
}
return 0;
}
