#include <stdio.h>
main()
{
    long i, n;											/*�������Ϊ������*/
    printf("please input a number:\n");
    scanf("%ld", &n);										/*�Ӽ�������������һ��������*/
    while (n != 1)										/*�����ս����Ϊ1ʱһֱִ��ѭ�������*/
    {
        if (n % 2 == 0)									/*�ж�n�Ƿ�Ϊż��*/
        {
            printf("%ld/2=%ld\n", n, n / 2);
            n = n / 2;									/*��nΪż��ʱn����2*/
        }
        else
        {
            printf("%ld*3+1=%ld\n", n, n *3+1);
            n = n * 3+1;									/*��nΪ����ʱ����3��1*/
        }
    }
}
