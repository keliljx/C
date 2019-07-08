#include<stdio.h>
#include<math.h>

double f(double x)			
{
	if(x!=0)
		return sin(x)/x;/*将x坐标值带入被积函数*/
	else
		return 1.0;
}
double result(double a,double b,double c)
{
	double S1=0.0,S2=0.0,S=0.0,h,x;
	int flag;
	h=b-a;				/*大梯形的高*/
	S1=h/2*(f(a)+f(b));/*大梯形的面积*/
	do
	{
		S=0;
		x=a+h/2;		/*二分点处的x坐标*/
		while(x<b)		
		{
			S=S+f(x);
			x=x+h;
		}
		S2=S1/2+h/2*S;	/*二分后两个小梯形的面积*/
		if(fabs(S1-S2)>=c)
		{
			h=h/2;
			S1=S2;
			flag=1;
		}
		else flag=0;
	}
	while(flag);
	return S2;
}
main()
{
	double a,b,c,m;
	printf("请输入积分的上、下限和精确度！\n");
	printf("请输入下限：");
	scanf("%lf",&a);
	printf("请输入上限：");
	scanf("%lf",&b);
	printf("请输入精确度：");
	scanf("%lf",&c);
	printf("计算出最终积分值是:");
	m=result(a,b,c);
	printf("%lf\n",m);

}