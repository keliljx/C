#include<stdio.h>
float func(float x,float y)
{
	return y-2*x/y;				/*求解的微分方程*/
}
float result(float x0,float y0,float h,float xn)
{
	float yp,yc;
	while(x0<xn)				/*在一定精度范围内*/
	{
		yp=y0+h*func(x0,y0);	/*整理后的预估矫正公式*/
		yc=y0+h*func(x0+h,yp);
		y0=1.0/2.0*(yp+yc);
		x0=x0+h;				/*迭代变量，步长为h*/
	}
	return y0;
}
main()
{
	float x0,y0,h,xn;
	printf("请输入初始值x0和y0\n");
	scanf("%f %f",&x0,&y0);
	printf("请输入步长\n");
	scanf("%f",&h);
	printf("请输入xn\n");
	scanf("%f",&xn);			/*输入上限*/
	printf("结果为：%f\n",result(x0,y0,h,xn));
	getche();
}
