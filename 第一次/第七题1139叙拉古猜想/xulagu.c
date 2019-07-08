# include <stdio.h>
int main()
{
    int n;
    scanf("%d",&n);

    if(n>1&&n<=10000)
    {
        printf("%d\n",n);
        while(n>1)
        {

            if(n%2==0)
            {
                n=n/2;
                printf("%d\n",n);
            }
            else
            {
                n= 3*n+1;
                printf("%d\n",n);
            }

        }
    }
else
    printf("wrong number");
    return 0;
}
