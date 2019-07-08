#include<math.h>
main()
{
	int i,j;
	double m,n=6,s,t=1;
	printf("i\t\tn\t\t\tn*n\n");			/*输出表头*/
	printf("1%16.0f%26.0f\n",n,n*n);		/*输出1位自守数*/
	for(i=2;i<=10;i++)						/*计算2~10位自守数*/
	{
		t*=10;								/*t依次为10,100,1000，…*/
		for(j=0;j<=9;j++)
		{
			s=j*t+n;						/*计算s，判断s是否为自守数*/
			m=fmod(s*s,t*10);				/*取s的平方的末i位赋给m*/
			if(s==m)						/*判断s与m是否相等，相等即为自守数*/
			{
				printf("%d%16.0f%26.0f\n",i,m,m*m);/*输出自守数*/
				n=m;						/*m赋给n用于下次循环*/
				break;						/*跳出内循环*/
			}
		}
	}
}