#include <math.h>
int sx(double n)
{
	double i,k;
	k=sqrt(n)+1;
	for(i=3;i<=k;i+=2)
		if(fmod(n,i)==0)			/*double型取余用fmod函数*/
			return 0;				/*不是素数返回0*/
		return 1;					/*是素数返回1*/
}
main()
{
	double i,k,t,p;

	for(p=2;p<=31;p++)
	{
		if(sx(p)==0)				/*判断p是否为素数*/
			continue;
		t=1;
		for(k=1;k<=p;k++)
			t=t*2;					/*2的p次方*/
		i=t/2;						/*2的p-1次方*/
		t--;						/*2的p次方减1*/
		if(sx(t)==1)
			printf("p=%3.0lf\ wq=%10.0lf*%10.0lf=%20.0lf\n",p,i,t,i*t);
	}
}