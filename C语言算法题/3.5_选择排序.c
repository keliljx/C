#include<stdio.h>
void main()
{
	int a[10];                     /*定义存放输入数字的一维数组*/
	int i,j,k,m;                   /*定义程序中用于循环的变量和中间变量*/
	printf("请输入10个数字,数字之间用空格隔开！\n");
	for(i=0;i<10;i++)
		scanf("%d",&a[i]);         /*数字输入*/
	for(i=0;i<9;i++)               /*选择排序*/
	{
		k=i;                       /*将i的值赋给k*/
		for(j=i+1;j<10;j++)        /*找出最小的数*/
			if(a[k]>a[j])
				k=j;
			if(k!=i)               /*将最小的数放到位置i处*/
			{
				m=a[i];
				a[i]=a[k];
				a[k]=m;
			}
	}
			printf("用选择法由小到大排序后为\n");
			for(i=0;i<10;i++)
				printf("%d ",a[i]);/*输出排好序的数字*/
			printf("\n");
}