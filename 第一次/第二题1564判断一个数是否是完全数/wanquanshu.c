#include<stdio.h>
int main()
{
    int n,i;
    int sum = 0;
    scanf("%d",&n);
    if(n>2)
    {
        for(i=1;i<n;++i)
            if(n%i==0)
            sum = sum + i;
        if(sum==n)
            printf("Yes\n");
        else
            printf("No\n");
    }
    else
        printf("���������2����");
    return 0;
}
