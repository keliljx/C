#include <stdio.h>
#include <stdlib.h>
int main()
{
  int x,y,z;/*���ұ�*/
   x=13;
   if(x==13)/*����13��*/
    {
      y=2+x;/*y-x==2*/
      z=x-1;/*x-z==1*/
      if(((y>x||y>z)&&(y-z==3))&&!(z<x&&x-y==2))
     printf("��=%d,��=%d,��=%d\n",x,y,z);
     }
    x=12;
   if(x==12)/*����12��*/ 
{
    y=x-2;
    z=x-1;
    if((y>x||y>z)&&(y-z==3))
   printf("��=%d,��=%d,��=%d\n",x,y,z);
}
  system("PAUSE");	
  return 0;
}
