#include<stdio.h>
float func(float x,float y)
{
	return y-2*x/y;				/*����΢�ַ���*/
}
float result(float x0,float y0,float h,float xn)
{
	float yp,yc;
	while(x0<xn)				/*��һ�����ȷ�Χ��*/
	{
		yp=y0+h*func(x0,y0);	/*������Ԥ��������ʽ*/
		yc=y0+h*func(x0+h,yp);
		y0=1.0/2.0*(yp+yc);
		x0=x0+h;				/*��������������Ϊh*/
	}
	return y0;
}
main()
{
	float x0,y0,h,xn;
	printf("�������ʼֵx0��y0\n");
	scanf("%f %f",&x0,&y0);
	printf("�����벽��\n");
	scanf("%f",&h);
	printf("������xn\n");
	scanf("%f",&xn);			/*��������*/
	printf("���Ϊ��%f\n",result(x0,y0,h,xn));
	getche();
}
