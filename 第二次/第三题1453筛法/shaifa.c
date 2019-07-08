#include<stdio.h>
int main()
{
    int m,n,i,j,k;
    scanf("%d%d",&m,&n);
    for(i=m; i<=n; i++)
    {
        for(k=2; k<i; k++)
        {
            if(i%k==0)
                break;
        }
        if(i==k)
            printf("%d\n",i);
    }
    return 0;
}
