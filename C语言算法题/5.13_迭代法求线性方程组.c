#include<stdio.h>
#include<math.h>
int result(float *x1,float *x2,float *x3,int l,float a)
{
	float p1=*x1,p2=*x2,p3=*x3;
	float pj1=100,pj2=100,pj3=100;
	int c=0;
	while((fabs(pj1-p1)>a||fabs(pj2-p2)>a||fabs(pj3-p3)>a)&&c<l)
	{
		pj1=p1;					/*将x（n+1）赋给x（n）*/
		pj2=p2;
		pj3=p3;
		p1=0.1*pj2+0.2*pj3+0.17;/*每一个变量的迭代公式*/
		p2=0.1*pj1+0.2*pj3+0.50;
		p3=0.2*pj1+0.2*pj2+0.58;
		c++;					/*累加迭代次数*/
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
	printf("输入迭代初值：\n");
	scanf("%f %f %f",&x1,&x2,&x3);
	printf("输入精度\n");
	scanf("%f",&a);
	printf("输入上限\n");
	scanf("%d",&l);
	if(result(&x1,&x2,&x3,l,a))
		printf("x1=%f;x2=%f;x3=%f\n",x1,x2,x3);
	else
		printf("迭代失败！请注意迭代初值、迭代次数和精度的输入是否匹配\n");
	getche();
}