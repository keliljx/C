#include<stdio.h>
#include<math.h>
double S(double);
double S(double a)
{
	double x1=a/2,x0=0.0;	/*迭代初值*/
	while(fabs(x1-x0)>0.0001)/*迭代结束条件*/
	{
		x0=x1;				
		x1=0.5*(x0+a/x0);	/*迭代公式*/
	}
	return x1;
}
main()
{
	double a,r;
	printf("请输入一个开平方数字：");
	scanf("%lf",&a);
	r=S(a);
	printf("对%f开平方的结果为：%f\n",a,r);
	getche();
}