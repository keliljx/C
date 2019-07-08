#include<stdio.h>
#include<string.h>
#define MAX 100
int a[MAX][MAX];
int main()
{
	int i,j,n,k=0,t=1;
	scanf("%d",&n);				//输入数组行列数n
	memset(a,0,sizeof(a));		//数组a清零
	for(i=n-1;i>=0;i--)			//遍历行
	{
		if(k==0)				//从右到左顺序依次递增1存数组元素
		{
			for(j=n-1;j>=0;j--)
				a[i][j]=t++;
			k=1;
		}
		else					//从左到右顺序依次递增1存数组元素
		{
			for(j=0;j<=n-1;j++)
				a[i][j]=t++;
			k=0;
		}
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
			printf("%4d",a[i][j]);//打印全部数组元素
		printf("\n\n");
	}
return 0;
}