#include<stdio.h>
int search(int a[],int n,int x);/*对调用的函数进行声明*/
void main()
{
	int i,x,z;       /*对变量进行定义*/
	int a[10];
	printf("请输入10个有序的数！\n");
	for(i=0;i<10;i++)
		scanf("%d",&a[i]);  /*接收10个有序的数赋值给数组a*/
	printf("请输入您要查找的数\n");
	scanf("%d",&x);        /*接收要查找的关键字并赋值给x*/
	z=search(a,10,x);      /*调用函数search()*/
	if(z)
		printf("您要查找的数%d在数组中的位置是第%d个元素\n",x,z);
	else
		printf("您要查找的数%d不在数组中！\n");
}
int search(int a[],int n,int x)  /*被调函数search()*/
{
	int low,mid,high;/*定义变量*/
	low=0;           /*给变量赋初值*/
	high=n-1;
	while(low<=high)  /*折半查找*/
	{
		mid=(low+high)/2;
		if(a[mid]==x)
			return mid+1;
		else if(a[mid]>x)
			high=mid-1;
		else low=mid+1;
	}
	return 0;
}