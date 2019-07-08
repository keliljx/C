# include<stdio.h>
int main()
{
    int i,n,t,min;
    scanf("%d",&n);
    scanf("%d",&t);
    min = t;
    for(i=1;i<n;i++)
    {
        scanf("%d",&t);
        if(t<min)
            min =t;
    }
    printf("%d\n",min);
    return 0;
}
