#include<stdio.h>
#include<stdlib.h>
main()
{
    int i;												 /*定义基本整型变量i*/
    for (i = 100; i < 1000; i++)								 /*for循环求一百到一千内的所有三位数*/
        if (i % 2 == 1 && i % 3 == 2 && i % 5 == 4 && i % 6 == 5 && i % 7 == 0)
													 /*根据题意写出对应的条件*/
            printf("the number of the stairs is %d\n", i);			 /*输出阶梯数*/
} 


