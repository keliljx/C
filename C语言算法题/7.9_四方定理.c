#include <stdio.h>
main()
{
    long i, j, k, l, n; 												/*�������Ϊ������*/
    printf("please input a number:\n");
    scanf("%ld", &n); 											/*�������Ϊ������*/
    for (i = 0; i <= n; i++)											/*��i��j��k��l�������*/
        for (j = 0; j <= i; j++)
            for (k = 0; k <= j; k++)
                for (l = 0; l <= k; l++)
                    if (i *i + j * j + k * k + l * l == n)					/*�ж��Ƿ����㶨��Ҫ�� */
    {
        printf("%ld*%ld+%ld*%ld+%ld*%ld+%ld*%ld=%ld\n", i, i, j, j, k, k, l, l,n);	/*������Ҫ��Ľ�����*/
        exit(0);
    }
}
