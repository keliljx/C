#include<stdio.h>
#include <stdlib.h>
int main()
{
    float a1 = 3, b1 = 1, c1 = 4, d1 = 5; /*定义变量为单精度型*/
    float day; /*定义天数为单精度型*/
    day = 1 / (1 / a1 + 1 / b1 + 1 / c1 + 1 / d1);
        /*计算四渠同时注水多久可以注满*/
    printf("need %f day!", day); /*将计算出的天数输出*/
    system("PAUSE");	
  return 0;
} 
