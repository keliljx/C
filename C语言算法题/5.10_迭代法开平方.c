#include<stdio.h>
#include<math.h>
double S(double);
double S(double a)
{
	double x1=a/2,x0=0.0;	/*������ֵ*/
	while(fabs(x1-x0)>0.0001)/*������������*/
	{
		x0=x1;				
		x1=0.5*(x0+a/x0);	/*������ʽ*/
	}
	return x1;
}
main()
{
	double a,r;
	printf("������һ����ƽ�����֣�");
	scanf("%lf",&a);
	r=S(a);
	printf("��%f��ƽ���Ľ��Ϊ��%f\n",a,r);
	getche();
}