#include <stdio.h>
#include <string.h>
#define MAXN 100+10
int a[MAXN];
int main()
{
	int i,j,n,k,first=1;
	memset(a,0,sizeof(a));//将数组a清零
	printf("输入灯的数量n和人数k：\n");
	scanf("%d%d",&n,&k);
	printf("输出最后开着的等的编号：\n");
	for(i=1;i<=k;i++)//k个人
		for(j=1;j<=n;j++)//n个灯
			if(j%i==0)
				a[j]=!a[j];//取反0变1,1变0
			for(i=1;i<=n;i++)
				if(a[i])//若a[j]是1说明开着
				{
					if(first)
						first=0;//判断是不是第一个数据，是第一个数据直接输出i，即灯的编号
					else 
						printf(" ");
					printf("%d",i);
				}
				printf("\n");	
return 0;
}
