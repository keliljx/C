#include <stdio.h>
#include <stdlib.h>

int main()
{
    static int a[82],a1[82],a2[82],a3[82],p,p1,p2,p3,m,n,i,k;
    for(i=0;i<=80;i++)
    {
        n=i;
        m=n%3;
        while(m>0){
            a[p]=i;m--;p++;           
        } 
        n/=3;
        if(n==0)    continue;
        m=n%3;
        while(m>0){
            a1[p1]=i;m--;p1++;           
        }                 
        n/=3;
        if(n==0)    continue;
        m=n%3;
        while(m>0){
            a2[p2]=i;m--;p2++;           
        }
        m=n/3;
        while(m>0){
            a3[p3]=i;m--;p3++;           
        }
    }
    printf("表1%27s表2\n"," "); 
    for(k=0;k<=8;k++){
        for(i=9*k;i<=9*k+8;i++)
            printf("%3d",a[i]);
        printf("%4s"," "); 
        for(i=9*k;i<=9*k+8;i++)
            printf("%3d",a1[i]);  
        printf("\n");               
    }
    printf("表3%27s表4\n"," "); 
    for(k=0;k<=8;k++){
        for(i=9*k;i<=9*k+8;i++)
            printf("%3d",a2[i]);
        printf("%4s"," "); 
        for(i=9*k;i<=9*k+8;i++)
            printf("%3d",a3[i]);  
        printf("\n");               
    }
    printf("\n键入你猜想的数一次在表1、表2、表3和表4中出现的次数：");
    scanf("%d%d%d%d",&p,&p1,&p2,&p3);
    n=p+p1*3+p2*9+p3*27;
    if(n==0)    n=81;
    printf("你猜想的数是：%d\n",n);
  system("PAUSE");	
  return 0;
}
