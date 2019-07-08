#include<stdio.h>
int main()
{
    int n,sum;
    scanf("%d",&n);
    sum=1;
    while(n!=1)
    {
        if(n%2==1)
        {
            n=3*n+1;
            sum=sum+1;
        }
        else
        {
            n=n/2;
            sum=sum+1;
        }
    }
    printf("%d\n",sum);
}
