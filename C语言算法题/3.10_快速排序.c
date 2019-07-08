#include<stdio.h>
int p(int a[],int low,int high);/*声明函数p*/
void q(int a[],int low,int high);/*声明函数q*/
void main()
{
	int a[10];         /*定义存放输入数字的一维数组*/
	int i;             /*定义程序中用于循环的变量*/
	printf("请输入10个数，数之间用空格隔开\n");
	for(i=0;i<10;i++)
		scanf("%d",&a[i]);/*接收输入的数组存储在数组a中*/
	q(a,0,9);           /*调用函数q*/
	printf("快速排序法由小到大排序为\n");
	for(i=0;i<10;i++)
	printf("%d ",a[i]);  /*输出排好序的数字*/
	printf("\n");
}
int p(int a[],int low,int high) /*函数p*/
{
	int key=a[low],p;
	while(low<high)
	{
		while(low<high && a[high]>=key)
			--high;
		p=a[low];a[low]=a[high];a[high]=p;
		while(low<high && a[low]<=key)
			++low;
		p=a[high];a[high]=a[low];a[low]=p;
	}
		a[low]=key;
		return low;
}

void q(int a[],int low,int high) /*函数q*/
{
	int j;
	if(low<high)
	{
		j=p(a,low,high);      /*调用函数p*/
		q(a,low,j-1);         /*调用函数q*/
		q(a,j+1,high);        /*调用函数q*/
	}
}
