#include<stdio.h>
#include<math.h>
int result(float *x1,float *x2,float *x3,int l,float a)
{
	float p1=*x1,p2=*x2,p3=*x3;
	float pj1=100,pj2=100,pj3=100;
	int c=0;
	while((fabs(pj1-p1)>a||fabs(pj2-p2)>a||fabs(pj3-p3)>a)&&c<l)
	{
		pj1=p1;					/*��x��n+1������x��n��*/
		pj2=p2;
		pj3=p3;
		p1=0.1*pj2+0.2*pj3+0.17;/*ÿһ�������ĵ�����ʽ*/
		p2=0.1*pj1+0.2*pj3+0.50;
		p3=0.2*pj1+0.2*pj2+0.58;
		c++;					/*�ۼӵ�������*/
	}
	if(fabs(pj1-p1)>a&&fabs(pj2-p2)>a&&fabs(pj3-p3)>a)
		return 0;
	else
	{
		*x1=p1;
		*x2=p2;
		*x3=p3;	
		return 1;
	}
}
main()
{
	float x1,x3,x2,a;
	int l;
	printf("���������ֵ��\n");
	scanf("%f %f %f",&x1,&x2,&x3);
	printf("���뾫��\n");
	scanf("%f",&a);
	printf("��������\n");
	scanf("%d",&l);
	if(result(&x1,&x2,&x3,l,a))
		printf("x1=%f;x2=%f;x3=%f\n",x1,x2,x3);
	else
		printf("����ʧ�ܣ���ע�������ֵ�����������;��ȵ������Ƿ�ƥ��\n");
	getche();
}