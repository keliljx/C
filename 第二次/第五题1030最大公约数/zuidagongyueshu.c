/*
辗转相除法
*/
#include<stdio.h>
int main()
{
 int a,b,temper;
 scanf("%d %d",&a,&b);
 while(b)
 {
  temper=a%b; a=b; b=temper;//辗转相除法，用大数除小数取余
                            //余数和当前的最小数再次辗转相除
 }
 printf("%d\n",a);
 return 0;
}
