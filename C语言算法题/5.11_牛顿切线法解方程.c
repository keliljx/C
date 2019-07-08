#include<stdio.h>
#include<math.h>
double fun(double x)/*代入牛顿公式，将值返回*/
{
	return x-(x-2*exp(-x))/(1+x);
}
double result(double x1,double a)
{/*传递的x1为初值，a为精确值*/
	double x2=0.0;
	x2=fun(x1);/*得到新的近似值*/
	while(fabs(x2-x1)>=a)/*判断精度*/
	{
		x1=x2;/*将新得到的近似值，赋给x1初值*/
		x2=fun(x1);/*将新得到的初值代入公式，将返回值赋给x2*/
	}
	return x2;/*返回最后近似解*/
}
main()
{
	double x1,a;
	printf("输入初值x1=");
	scanf("%lf",&x1);
	printf("输入精确值a=");
	scanf("%lf",&a);
	printf("方程的近似解x=%lf\n",result(x1,a));
	getche();
	
}
	