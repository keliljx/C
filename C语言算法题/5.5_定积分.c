#include "stdio.h"
#include "stdlib.h"
#include "time.h"
#include "math.h"

double p(int n)
{
	double x,y;
	time_t t;
	int i,count=0;
	srand((unsigned)time(&t));
	for(i=0;i<n;i++)
	{
		x=rand()%100/100.0;
		y=rand()%100/100.0;
		if(y<=1-pow(x,2))
			count++;
	}
	return (double)count/(double)n;
}
main()
{
	int n;
	printf("Please input the accuracy:");
	scanf("%d",&n);
	printf("The result is about:");
	printf("%f\n",p(n));
	getche();
}