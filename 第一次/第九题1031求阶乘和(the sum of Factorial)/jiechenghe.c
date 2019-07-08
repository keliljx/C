# include <stdio.h>
int main( )
{
    int n,i,j;
    int m =1;
    int sum = 0;
    scanf("%d",&n);
    for (i=1;i<=n;i++)
    {
        for(j=1,m=1;j<=i;j++)
            m=m*j;
            sum=sum+m;

    }

  printf("%d\n",sum);

    return 0;
}
