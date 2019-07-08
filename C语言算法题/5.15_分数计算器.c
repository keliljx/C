#include<stdio.h>
int gys(int x,int y)							/*定义求最大公约数函数*/
{
  return y?gys(y,x%y):x;					/*递归调用gys，利用条件语句返回最大公约数*/
}
int gbs(int x,int y)							/*定义求最小公倍数函数*/
{
  return x/gys(x,y)*y;
}
void yuefen(int fz,int fm)					/*定义约分函数*/
{ 
  int s=gys(fz,fm);
  fz/=s;
  fm/=s;
  printf("the result is %d/%d\n",fz,fm);
}
void add(int a,int b,int c,int d)					/*定义加法函数*/
{
  int u1,u2,v=gbs(b,d),fz1,fm1;
  u1=v/b*a;
  u2=v/d*c;
  fz1=u1+u2;
  fm1=v;
  yuefen(fz1,fm1);
}
void sub(int a,int b,int c,int d)					/*定义减法函数*/
{   
  int u1,u2,v=gbs(b,d),fz1,fm1;
  u1=v/b*a;
  u2=v/d*c;
  fz1=u1-u2;
  fm1=v;
  yuefen(fz1,fm1);
}
void mul(int a,int b,int c,int d)					/*定义乘法函数*/
{ 
  int u1,u2;
  u1=a*c;
  u2=b*d;
  yuefen(u1,u2);
}

void div(int a,int b,int c,int d)					/*定义除法函数*/
{
  int u1,u2;
  u1=a*d;
  u2=b*c;
  yuefen(u1,u2);
}
main()
{ 
  char op;
  int a,b,c,d;
  printf("输入数1、四则运算符号、数2：\n");
  scanf("%ld,%ld,%c,%ld,%ld",&a,&b,&op,&c,&d);
  switch(op)							/*根据输入的符号选择不同函数的调用*/
  {
   case '+':add(a,b,c,d);break;				/*调用加法函数*/
   case '*':mul(a,b,c,d);break;				/*调用乘法函数*/
   case '-':sub(a,b,c,d);break;					/*调用减法函数*/
   case '/':div(a,b,c,d);break;					/*调用除法函数*/
  }
} 
