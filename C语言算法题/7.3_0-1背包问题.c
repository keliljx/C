#include<stdio.h>
int x[100];            /*记录物品存放状态*/
int pValue[100]={0};   /*物品的单价*/
int pWeight[100]={0};  /*物品的重量*/

void knapsack0(int n,int flag,int c,int *price)  /*获取最大价值*/
{
	int i, j,p;
	if(bound(n,c)) return;      /*判断是否超出包的承重量*/
	if(n==flag)
	{
		p=getvalue(n);			/*获取包中物品的总价值*/
		if(*price<p) 
			*price=p;
		return;
	}
	for(i=0;i<=1;i++)
	{
		x[n]=i;							/*设置放置标识*/
		knapsack0(n+1,flag,c,price);	/*递归回溯*/
	}
	
}
void knapsack1(int n,int flag,int c,int *price)
{
	int i, j,p;
	
	if(bound(n,c)) return;			/*判断是否超出包的承重量*/
	if(n==flag)
	{
		p=getvalue(n);				/*获取包中物品总价值*/
		if(*price==p)				/*如果与最大价值相等，则输出包中物品*/
		{
			printf("\n\n包里的物品为：\n");
			for(j=0;j<n;j++)
				if(x[j]==1)
				{
					printf("物品编号：%d\n",j);		/*输出物品编号*/
					printf("重量： %d kg\n",pWeight[j]);		/*输出物品重量*/
					printf("价格： %d $\n\n",pValue[j]);		/*输出物品价格*/
				}
		}
		return;
	}
	for(i=0;i<=1;i++)
	{
		x[n]=i;
		knapsack1(n+1,flag,c,price);				/*递归回溯*/
	}
	
}

int bound(int n,int c)		/*计算物品重量是否超重，超重返回1，否则返回0*/
{
	int i,w=0;
	for(i=0;i<n;i++)
		w=w+x[i]*pWeight[i];	/*根据包中物品计算重量*/
	if (w>c) return 1;			/*超重*/
	else return 0;
}

int getvalue(int n)			/*计算物品总价值*/
{
	int i,v=0;
	for(i=0;i<n;i++)
		v=v+x[i]*pValue[i];		/*根据包中物品计算价值*/
	return v;
	
}
main()
{
	int i,n,c;
	int price=0;
	printf("输入物品数量: \n");
	scanf("%d",&n);
	printf("输入包的最大承重量:\n");
	scanf("%d",&c);
	printf("输入每个物品的重量\n");
	for(i=0;i<n;i++)
		scanf("%d",&pWeight[i]);
	printf("输入每个物品的价值\n");
	for(i=0;i<n;i++)
		scanf("%d",&pValue[i]);	
	knapsack0(0,n,c,&price);			/*获取可能的最大价值*/
	printf("最大价值为：%d",price);
	
	knapsack1(0,n,c,&price);			/*输出包中物品*/
}