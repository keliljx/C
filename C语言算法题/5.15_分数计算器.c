#include<stdio.h>
int gys(int x,int y)							/*���������Լ������*/
{
  return y?gys(y,x%y):x;					/*�ݹ����gys������������䷵�����Լ��*/
}
int gbs(int x,int y)							/*��������С����������*/
{
  return x/gys(x,y)*y;
}
void yuefen(int fz,int fm)					/*����Լ�ֺ���*/
{ 
  int s=gys(fz,fm);
  fz/=s;
  fm/=s;
  printf("the result is %d/%d\n",fz,fm);
}
void add(int a,int b,int c,int d)					/*����ӷ�����*/
{
  int u1,u2,v=gbs(b,d),fz1,fm1;
  u1=v/b*a;
  u2=v/d*c;
  fz1=u1+u2;
  fm1=v;
  yuefen(fz1,fm1);
}
void sub(int a,int b,int c,int d)					/*�����������*/
{   
  int u1,u2,v=gbs(b,d),fz1,fm1;
  u1=v/b*a;
  u2=v/d*c;
  fz1=u1-u2;
  fm1=v;
  yuefen(fz1,fm1);
}
void mul(int a,int b,int c,int d)					/*����˷�����*/
{ 
  int u1,u2;
  u1=a*c;
  u2=b*d;
  yuefen(u1,u2);
}

void div(int a,int b,int c,int d)					/*�����������*/
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
  printf("������1������������š���2��\n");
  scanf("%ld,%ld,%c,%ld,%ld",&a,&b,&op,&c,&d);
  switch(op)							/*��������ķ���ѡ��ͬ�����ĵ���*/
  {
   case '+':add(a,b,c,d);break;				/*���üӷ�����*/
   case '*':mul(a,b,c,d);break;				/*���ó˷�����*/
   case '-':sub(a,b,c,d);break;					/*���ü�������*/
   case '/':div(a,b,c,d);break;					/*���ó�������*/
  }
} 
