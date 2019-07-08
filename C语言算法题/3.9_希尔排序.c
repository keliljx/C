#include<stdio.h>
void main()
{
	int a[10];                 /*定义存放输入数字的一维数组*/
	int i,j,k,t;               /*定义程序中用于循环的变量和中间变量*/
	printf("请输入10个数，数字之间用空格隔开！\n");
	for(i=0;i<10;i++)
		scanf("%d",&a[i]);     /*数字输入*/
	k=10/2;
	while(k>0)                 /*希尔排序*/
	{
		for(i=k;i<10;i++)
		{
			j=i-k;
			while(j>=0)
				if(a[j]>a[j+k])
				{t=a[j];a[j]=a[j+k];a[j+k]=t;j-=k;}
				else break;
		}
		k/=2;
	}
	printf("您输入的数字按希尔排序法由小到大排序为：\n");
	for(i=0;i<10;i++)
		printf("%d ",a[i]);   /*输出排好序的数字*/
	printf("\n");
}