#include <stdio.h>
int main()
{
	double a,c,x=0,y=100;
	int i,b;
	printf("请输入向银行借多少钱：");
	scanf("%lf",&a);
	printf("请输入分几个月还清：");
	scanf("%d",&b);
	printf("请输入每月还多少钱：");
	scanf("%lf",&c);
	while(y-x>1e-3)						/*在确定的精度下计算x值*/
	{
		double m=x+(y-x)/2;				/*对x所在范围二分*/
		double f=a;
		for(i=0;i<b;i++)				/*在b个月内还贷款*/
			f+=f*m/100.0-c;
		if(f<0)							
			x=m;						/*x的值过大*/
		else
			y=m;
	}
	printf("%.3lf%%\n",x);
	return 0;
}