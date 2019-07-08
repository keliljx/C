#include<math.h>
main()
{
	long a[32],i,j,b,c,t,m=0;
	printf("六位数的一数三平方数：\n");
	for(i=0;i<=31;i++)				/*统计出从0到999之内的所有平方数*/
		a[i]=i*i;
	for(i=31;i>=10;i--)
	{
		b=1000*a[i];				/*高三位数*/
		for(j=31;j>=0;j--)
		{
			c=b+a[j];				/*六位数*/
			t=sqrt(c);				/*六位数开方*/
			if(c==t*t)				/*判断六位数是否为平方数*/
			{
				printf("%9ld\n\n",c);/*是则输出*/
				m++;				/*累积个数*/
			}
		}
	}
	printf("共有%ld个六位数的一数三平方数。\n",m);
}