#include<stdio.h>
int search(int a[],int y,int x);/*对自定义的函数search进行声明*/
void main()
{
	int i,x,n;  /*变量定义*/
	int a[10];
	printf("请输入10个数字！\n");
	for(i=0;i<10;i++)
		scanf("%d",&a[i]);/*接收输入的数组*/
	printf("请输入要查找的数：");
	scanf("%d",&x);  /*接收关键字*/
	n=search(a,10,x);/*调用函数search()完成顺序查找*/
	if(n<0)   /*输出要找的数的位置*/
		printf("没找到您要找的数,您要找的数可能不在数组中。\n");
	else
		printf("您要找的数%d在数组中第%d个元素处。\n",x,n);
}
int search(int a[],int y,int x)/*被调用的函数search()*/
{
	int i,f=-1;
	for(i=0;i<10;i++)
		if(x==a[i])
		{
			f=i+1;
			break;
		}
		return(f);
}
