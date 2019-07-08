#include<stdio.h>
int a(int m,int n)			/*求最大公约数*/
{
	int min;
	if(m<=0||n<=0)
		return -1;
	if(m>n)					/*取输入的两个数中最小的数赋给min*/
		min=n;
	else
		min=m;
	while(min)				
	{
		if(m%min==0&&n%min==0)	/*分别对min取余*/
			return min;			/*返回最大公约数*/
		min--;
	}
	return -1;
}
int b(int m,int n)
{
	int max;
	if(m<=0||n<=0)
		return -1;
	if(m>n)						/*将m和n两个数中最大的数赋给max*/
		max=m;
	else
		max=n;
	while(max)
	{
		if(max%m==0&&max%n==0)	/*求最小公倍数*/
			return max;
		max++;
	}
	return -1;
}
main()
{
	int m,n;
	printf("请输入两个数，求这两个数的最大公约数和最小公倍数！\n");
	scanf("%d %d",&m,&n);
	printf("%d和%d的最大公约数是%d\n",m,n,a(m,n));
	printf("%d和%d的最小公倍数是%d\n",m,n,b(m,n));

}