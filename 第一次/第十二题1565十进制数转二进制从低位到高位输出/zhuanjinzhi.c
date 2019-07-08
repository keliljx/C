#include <stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    while(n)
    {
        printf("%d\n",n%2);
        n /= 2;
    }
}
