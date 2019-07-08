#include <stdio.h>
main()
{
    long i, j, k, l, n; 												/*定义变量为长整型*/
    printf("please input a number:\n");
    scanf("%ld", &n); 											/*定义变量为长整型*/
    for (i = 0; i <= n; i++)											/*对i，j，k，l进行穷举*/
        for (j = 0; j <= i; j++)
            for (k = 0; k <= j; k++)
                for (l = 0; l <= k; l++)
                    if (i *i + j * j + k * k + l * l == n)					/*判断是否满足定理要求 */
    {
        printf("%ld*%ld+%ld*%ld+%ld*%ld+%ld*%ld=%ld\n", i, i, j, j, k, k, l, l,n);	/*将满足要求的结果输出*/
        exit(0);
    }
}
