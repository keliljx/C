#include<stdio.h>
#include<math.h>
double fun(double x)/*����ţ�ٹ�ʽ����ֵ����*/
{
	return x-(x-2*exp(-x))/(1+x);
}
double result(double x1,double a)
{/*���ݵ�x1Ϊ��ֵ��aΪ��ȷֵ*/
	double x2=0.0;
	x2=fun(x1);/*�õ��µĽ���ֵ*/
	while(fabs(x2-x1)>=a)/*�жϾ���*/
	{
		x1=x2;/*���µõ��Ľ���ֵ������x1��ֵ*/
		x2=fun(x1);/*���µõ��ĳ�ֵ���빫ʽ��������ֵ����x2*/
	}
	return x2;/*���������ƽ�*/
}
main()
{
	double x1,a;
	printf("�����ֵx1=");
	scanf("%lf",&x1);
	printf("���뾫ȷֵa=");
	scanf("%lf",&a);
	printf("���̵Ľ��ƽ�x=%lf\n",result(x1,a));
	getche();
	
}
	