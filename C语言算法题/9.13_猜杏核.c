#include <stdio.h>
#include <stdlib.h>
int main()
{
  int x,y,z;/*¼×ÒÒ±û*/
   x=13;
   if(x==13)/*¼×ÓÐ13Á£*/
    {
      y=2+x;/*y-x==2*/
      z=x-1;/*x-z==1*/
      if(((y>x||y>z)&&(y-z==3))&&!(z<x&&x-y==2))
     printf("¼×=%d,ÒÒ=%d,±û=%d\n",x,y,z);
     }
    x=12;
   if(x==12)/*¼×ÓÐ12Á£*/ 
{
    y=x-2;
    z=x-1;
    if((y>x||y>z)&&(y-z==3))
   printf("¼×=%d,ÒÒ=%d,±û=%d\n",x,y,z);
}
  system("PAUSE");	
  return 0;
}
