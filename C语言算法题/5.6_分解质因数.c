#include <stdio.h>
int a(int a)
{
	int i;
	for(i=2;i<=a-1;i++)
		if(a%i==0)
			return 0;
		return 1;
}
void factorization(int n)
{
	int i;
	if(a(n))
		printf("%dÊÇÖÊÊý£¡\n",n);
	else
	{	printf("%d=",n);

		for(i=2;i<=n-1;i++)
		if(n%i==0)
		{
			printf("%d*",i);
			if(a(n/i))
			{
				printf("%d\n",n/i);
				break;
			}
			else
				factorization(n/i);
			break;
		}
	}
}
main()
{
	int n;
	printf("input n=");
	scanf("%d",&n);
	factorization(n);

}
