#include<stdio.h>
#include<math.h>

double f(double x)			
{
	if(x!=0)
		return sin(x)/x;/*��x����ֵ���뱻������*/
	else
		return 1.0;
}
double result(double a,double b,double c)
{
	double S1=0.0,S2=0.0,S=0.0,h,x;
	int flag;
	h=b-a;				/*�����εĸ�*/
	S1=h/2*(f(a)+f(b));/*�����ε����*/
	do
	{
		S=0;
		x=a+h/2;		/*���ֵ㴦��x����*/
		while(x<b)		
		{
			S=S+f(x);
			x=x+h;
		}
		S2=S1/2+h/2*S;	/*���ֺ�����С���ε����*/
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
	printf("��������ֵ��ϡ����޺;�ȷ�ȣ�\n");
	printf("���������ޣ�");
	scanf("%lf",&a);
	printf("���������ޣ�");
	scanf("%lf",&b);
	printf("�����뾫ȷ�ȣ�");
	scanf("%lf",&c);
	printf("��������ջ���ֵ��:");
	m=result(a,b,c);
	printf("%lf\n",m);

}