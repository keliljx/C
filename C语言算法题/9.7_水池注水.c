#include<stdio.h>
#include <stdlib.h>
int main()
{
    float a1 = 3, b1 = 1, c1 = 4, d1 = 5; /*�������Ϊ��������*/
    float day; /*��������Ϊ��������*/
    day = 1 / (1 / a1 + 1 / b1 + 1 / c1 + 1 / d1);
        /*��������ͬʱעˮ��ÿ���ע��*/
    printf("need %f day!", day); /*����������������*/
    system("PAUSE");	
  return 0;
} 
