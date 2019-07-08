#include<stdio.h>
void main()
{
	int a[10];                    /*定义存放输入数字的一维数组*/
	int i,j,k;                    /*定义程序中用于循环的变量和中间变量*/
	printf("请输入10个数，用空格隔开，以回车结束！\n");
	for(i=0;i<10;i++)
		scanf("%d",&a[i]);         /*数字输入*/
	for(i=0;i<9;i++)               /*冒泡排序*/
		for(j=0;j<9-i;j++)
			if(a[j]>a[j+1])        /*相邻两数进行比较，小的放前大的放后*/
			{
				k=a[j];
				a[j]=a[j+1];
				a[j+1]=k;
			}
			printf("您输入的数字按冒泡法由小到大排序后为\n");
			for(i=0;i<10;i++)
				printf("%d ",a[i]); /*输出排好序的数字*/
			printf("\n");
}