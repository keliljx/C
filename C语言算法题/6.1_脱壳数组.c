#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int repqat(double n)
{
    int m,b[10],c,y;
    for(c=0;c<=9;c++)    b[c]=0;
    m=(int)log10(n)+1; 
    for(c=1;c<=m;c++){
        y=fmod(n,10);b[y]++;n=n/10;
        }
        y=0; 
        for(c=0;c<=9;c++)
            if(b[c]==1)    y++;
        if(y==m)    return 1;
        else        return 0;                
}
int main()
{
  double i,r,s;
  int a[100],j,k,q,w;
  printf("\n\n一位和两位的平方数如是：");
  for(j=0;j<=9;j++){
      a[j]=j*j;
      printf("%4d",a[j]);                  
  }
  printf("\n\n金蝉平方数是：");
  for(i=sqrt(100);i<=sqrt(9876543210);i++){                                    
      r=s=i*i;
      if(repqat(s)!=1)  continue;
      w=log10(s)+1;
      while(w>2){
          r=fmod(r,pow(10,w-1));
          r=(long)(r/10);
          q=sqrt(r);
          if(r!=q*q)    goto h;
          w=w-2;           
      }  
      for(j=0;j<=9;j++)
           if(r==a[j])     printf("%6.0lf",s);
      h:;                                       
  }
  printf("\n");
  system("PAUSE");	
  return 0;
}
