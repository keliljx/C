#include<stdio.h>
#include<stdlib.h>
main()
{
    int i;												 /*����������ͱ���i*/
    for (i = 100; i < 1000; i++)								 /*forѭ����һ�ٵ�һǧ�ڵ�������λ��*/
        if (i % 2 == 1 && i % 3 == 2 && i % 5 == 4 && i % 6 == 5 && i % 7 == 0)
													 /*��������д����Ӧ������*/
            printf("the number of the stairs is %d\n", i);			 /*���������*/
} 


