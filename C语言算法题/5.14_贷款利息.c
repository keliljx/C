#include <stdio.h>
int main()
{
	double a,c,x=0,y=100;
	int i,b;
	printf("�����������н����Ǯ��");
	scanf("%lf",&a);
	printf("������ּ����»��壺");
	scanf("%d",&b);
	printf("������ÿ�»�����Ǯ��");
	scanf("%lf",&c);
	while(y-x>1e-3)						/*��ȷ���ľ����¼���xֵ*/
	{
		double m=x+(y-x)/2;				/*��x���ڷ�Χ����*/
		double f=a;
		for(i=0;i<b;i++)				/*��b�����ڻ�����*/
			f+=f*m/100.0-c;
		if(f<0)							
			x=m;						/*x��ֵ����*/
		else
			y=m;
	}
	printf("%.3lf%%\n",x);
	return 0;
}