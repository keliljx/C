#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int a[20];
int n,sum=0;
int main() 
{
	int i;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	search(1);
	printf("%d\n",sum);
	return 0;
}

int search(int m)
{
	int i,temp;
	if(m==n)
	{
		if(isprime(a[n-1]+a[0]))
		sum=sum+1;
	} 
	else
	{
		if(m>0)
		{
			for(i=m;i<n;i++)
		{
			if(isprime(a[i]+a[m-1]))
			{
				temp=a[m];
				a[m]=a[i];
				a[i]=temp;
				search(m+1);
				temp=a[m];
				a[m]=a[i];
				a[i]=temp;				
			}
		}
		}

	}
}

int isprime(int q)
{
	int i,flag=1;
	if(q==1)
	flag=0;
	if(q%2==0&&q!=2)
	flag=0;
	for(i=3;i<=sqrt(q);i=i+2)
	{
		if(q%i==0)
		flag=0;
	}
	return flag;
}
