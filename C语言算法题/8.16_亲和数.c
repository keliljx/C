#include<math.h>
main()
{
	unsigned long i,n,s,m,k;
	int t=1;
	for(n=210;n<=10000;n++)				/*���n*/
	{
		s=1;							/*sΪn��������֮��*/
		k=1;							/*�ۼ������Ӹ���*/
		for(i=2;i<=sqrt(n);i++)			/*���������֮��*/
			if(n%i==0)
			{
				s=s+i+n/i;
				k+=2;
			}
			if(k==1||s<=n)				/*��nΪ������sС�ڵ���n������������*/
				continue;
			m=1;						/*mΪs��������֮��*/
			for(i=2;i<=sqrt(s);i++)
				if(s%i==0)
					m+=i+s/i;			/*����s��������֮��*/
				if(m==n)				/*���������ȣ�����׺���*/
				{
					printf("�׺�����%d�ԣ�\n",t++);
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