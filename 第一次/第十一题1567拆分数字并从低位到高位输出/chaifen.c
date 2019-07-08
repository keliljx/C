# include <stdio.h>#include<stdio.h>
int fun(int num);
int main()
{
    int n;
    scanf("%d", &n);
    fun(n);
    return 0;
}
int fun(int num)
{
    if (num < 10)
    {
        printf("%d\n",num);
    }
    else
    {
        printf("%d\n",num % 10);
        fun(num / 10);
    }
    return 0;
}
