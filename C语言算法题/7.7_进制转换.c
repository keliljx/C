#include <stdio.h>
#include <string.h>

main()
{
    long t1;
    int i, n, t, t3;
    char a[100];
    printf("please input a number string:\n");
    gets(a);											/*����n�������浽����a��*/
    strupr(a);											/*��a�е�Сд��ĸת���ɴ�д��ĸ*/
    t3 = strlen(a);										/*�������a�ĳ���*/
    t1 = 0;												/*Ϊt1����ֵ0*/
    printf("please input n(2or8or16):\n");
    scanf("%d", &n);										/*���������*/
    for (i = 0; i < t3; i++)
    {
        if (a[i] - '0' >= n && a[i] < 'A' || a[i] - 'A' + 10 >= n)			/*�ж���������ݺͽ������Ƿ����*/
        {
            printf("data error!!");							/*�������*/
            exit(0);										/*�˳�����*/
        }
        if (a[i] >= '0' && a[i] <= '9')							/*�ж��Ƿ�Ϊ����*/
            t = a[i] - '0';									/*��������ָ���t*/
        else if (n >= 11 && (a[i] >= 'A' && a[i] <= 'A' + n - 10))		/*�ж��Ƿ�Ϊ��ĸ*/
            t = a[i] - 'A' + 10;								/*�����ĸ�������ʮ������*/
        t1 = t1 * n + t;									/*�������ת���ɵ�ʮ������*/
    }
    printf("the decimal is %ld\n", t1);							/*�����ս�����*/
} 


