#include <math.h>
int sx(double n)
{
	double i,k;
	k=sqrt(n)+1;
	for(i=3;i<=k;i+=2)
		if(fmod(n,i)==0)			/*double��ȡ����fmod����*/
			return 0;				/*������������0*/
		return 1;					/*����������1*/
}
main()
{
	double i,k,t,p;

	for(p=2;p<=31;p++)
	{
		if(sx(p)==0)				/*�ж�p�Ƿ�Ϊ����*/
			continue;
		t=1;
		for(k=1;k<=p;k++)
			t=t*2;					/*2��p�η�*/
		i=t/2;						/*2��p-1�η�*/
		t--;						/*2��p�η���1*/
		if(sx(t)==1)
			printf("p=%3.0lf\ wq=%10.0lf*%10.0lf=%20.0lf\n",p,i,t,i*t);
	}
}