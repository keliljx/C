#include <stdio.h>
main()
{
    long i, n;											/*定义变量为长整形*/
    printf("please input a number:\n");
    scanf("%ld", &n);										/*从键盘中任意输入一长整形数*/
    while (n != 1)										/*当最终结果不为1时一直执行循环体语句*/
    {
        if (n % 2 == 0)									/*判断n是否为偶数*/
        {
            printf("%ld/2=%ld\n", n, n / 2);
            n = n / 2;									/*当n为偶数时n除以2*/
        }
        else
        {
            printf("%ld*3+1=%ld\n", n, n *3+1);
            n = n * 3+1;									/*当n为奇数时乘以3加1*/
        }
    }
}
