#include<math.h>
main()
{
	unsigned long i,n,s,m,k;
	int t=1;
	for(n=210;n<=10000;n++)				/*穷举n*/
	{
		s=1;							/*s为n的真因子之和*/
		k=1;							/*累记真因子个数*/
		for(i=2;i<=sqrt(n);i++)			/*求解真因子之和*/
			if(n%i==0)
			{
				s=s+i+n/i;
				k+=2;
			}
			if(k==1||s<=n)				/*若n为素数或s小于等于n，程序继续穷举*/
				continue;
			m=1;						/*m为s的真因子之和*/
			for(i=2;i<=sqrt(s);i++)
				if(s%i==0)
					m+=i+s/i;			/*计算s的真因子之和*/
				if(m==n)				/*如果两数相等，输出亲和数*/
				{
					printf("亲和数第%d对！\n",t++);
					printf("%lu:1",n);
					for(i=2;i<=sqrt(n);i++)
						if(n%i==0)
							printf("+%lu+%lu",i,n/i);
						printf("=%lu\n",s);
						printf("%lu:1",s);
						for(i=2;i<=sqrt(s);i++)
							if(s%i==0)
								printf("+%lu+%lu",i,s/i);
							printf("=%lu\n\n",n);
				}
	}
}