#include<stdio.h>
int a[100][100],m,n;
void search(int j,int k);
void search(int j,int k)
{
	if(a[j][k]==0)
	{
	    a[j][k]=2;
	    if(j>=1)
		{
			search(j-1,k);
		}
		if(j<m-1)
		{
			search(j+1,k);
		}
		if(k>=1)
		{
			search(j,k-1);
		}
		if(k<n-1)
		{
			search(j,k+1);
		}
	}
}
int main()
{
	scanf("%d %d",&m,&n);
	int j,k;
	scanf("%d %d",&j,&k);
	int p,q;
	scanf("%d %d",&p,&q);
	int i,e;
	for(i=0;i<m;i++)
	{
		for(e=0;e<n;e++)
		{
			scanf("%d",&a[i][e]);
		}
	}
	search(j,k);
	if(a[p][q]==2)
	{
		printf("Yes\n");
	}else
	{
		printf("No\n");
	}

}
