#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i,j,n,k,h,m=1,a[20][20]={0},z;
    char *s[2]={"顺时针方向螺旋阵","逆时针方向螺旋阵"};
    while(1)
    {
         printf("\n\n输入行数n（1到19）：");
         scanf("%d",&n);
         if(n<1||n>19)    break;
         printf("\n\n选择螺旋方向：1.顺时针 2.逆时针：");
         scanf("%d",&z);
         printf("\n");
         m=1;
         if(z==1)
         {
             for(i=1;i<=n/2;i++){
                  h=i;
                  for(k=i;k<=n-i;k++)     a[h][k]=m++;
                  k=n+1-i;
                  for(h=i;h<=n-i;h++)     a[h][k]=m++;
                  h=n+1-i;
                  for(k=n+1-i;k>=i+1;k--)     a[h][k]=m++;
                  k=i;
                  for(h=n+1-i;h>=i+1;h--)     a[h][k]=m++;                   
             }        
         } 
         else
         {
             for(i=1;i<=n/2;i++)
             {
                 k=i;
                 for(h=i;h<=n+1-i;h++)     a[h][k]=m++;
                 h=n+1-i;
                 for(k=i+1;k<=n+1-i;k++)     a[h][k]=m++;
                 k=n+1-i;
                 for(h=n-i;h>=i;h--)    a[h][k]=m++;
                 h=i;
                 for(k=n-i;k>=i+1;k++)      a[h][k]=m++;                   
             }    
         } 
         if(n%2==1)    a[n/2+1][n/2+1]=m;
         printf("\t%s\n\n",s[z-1]);  
         for(i=1;i<=n;i++)
         {
             for(j=1;j<=n;j++)
                 printf("%4d",a[i][j]);
             printf("\n");                 
         }    
    } 
  system("PAUSE");	
  return 0;
}
