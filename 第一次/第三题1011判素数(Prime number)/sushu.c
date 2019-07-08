/*
判断素数的方法：用一个数分别去除2到sqrt(这个数)，
如果能被整除，则表明此数不是素数，反之是素数。
*/
#include<stdio.h>
#include<math.h>
int main()
{
    int n,i,k;
    scanf("%d",&n);
    k=sqrt(n);


    for(i=2; i<=k; i++)//注意从2开始，若从1开始，则都符合
        if(n%i==0)
            break;
    if(i>k)
        printf("Yes\n");
    else
        printf("No\n");




    return 0;
}
