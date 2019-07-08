#include<stdio.h>

int main()
{
	int m, n, x, y, k, a[20], b[20], c[40];
	scanf("%d",&m);
	for(x=0;x<m;x++)
	{
		scanf("%d",&a[x]);
	}
	scanf("%d",&n);
	for(y=0;y<n;y++)
	{
		scanf("%d",&b[y]);
	}
	x=0;
	y=0;
	k=0;
	while(x<m && y<n)
	{
		if(a[x]<=b[y])
		{
			c[k]=a[x];
			k++;
			x++;
		}
		else
		{
			c[k]=b[y];
			k++;
			y++;
		}
	}
	while(x<m)
	{
		c[k]=a[x];
		k++;
		x++;
	}
	while(y<n)
	{
		c[k]=b[y];
		k++;
		y++;
	}
	for(k=0;k<m+n;k++)
	{
		printf("%d\n",c[k]);
	}
	return 0;
}