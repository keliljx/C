#include <stdio.h>
#include <string.h>

int main()
{
	int used[1000] ;
	int count ;
	int left[1000] ;
	int out;
	int i ;
	int peoplenum , sound ;



	while(scanf("%d%d",&peoplenum,&sound)!=EOF)
	{
		peoplenum *=2;
		memset(used,0,sizeof(int)*100) ;
		out = 0 ;
		count = 0 ;
		i = 0 ;
		while(out<peoplenum)
		{
			if (i>peoplenum)
				i -= peoplenum;
			if (i<0)
			{
				i+=peoplenum;
			}
			if(used[i]==0)
			{
				count++ ;
				if(count==sound)
				{
					count = 0 ;
					used[i]=1 ;
					left[out++]=i ;
				}
			}
			if (out >= peoplenum/2)
			{
				i--;
				continue;
			}
			i++;
		}
		printf("%d\n",left[peoplenum-1]+1);
	}

	return 0 ;
}
