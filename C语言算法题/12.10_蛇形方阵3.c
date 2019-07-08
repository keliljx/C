#include<stdio.h>
#include<string.h>
#define MAXN 100
int a[MAXN][MAXN];
int main()
{
	int n,i,j,t=0;
	scanf("%d",&n);
	memset(a,0,sizeof(a));//清零
	t=a[i=0][j=n-1]=1;//第0行第n-1列输入起始1
	while(t<n*n)//数组中的数不超过n*n
	{
		while(i+1<n && !a[i+1][j])//向下赋值
			a[++i][j]=++t;
		while(j-1>=0&&!a[i][j-1])//向左赋值
			a[i][--j]=++t;
		while(i-1>=0&&!a[i-1][j])//向上赋值
			a[--i][j]=++t;
		while(j+1<n&&!a[i][j+1])//向左赋值
			a[i][++j]=++t;
	}
	for(i=0;i<n;i++)//遍历二维数组，输出
	{
		for(j=0;j<n;j++)
			printf("%4d",a[i][j]);
		printf("\n\n");
	}
	return 0;

}
