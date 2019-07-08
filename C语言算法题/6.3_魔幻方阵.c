#include <stdio.h>
#include <stdlib.h>
int  ne(int i,int j,int k,int l,int m,int n,int o,int p,int q)
{
    if(i!=j&&i!=k&&i!=l&&i!=m&&i!=n&&i!=o&&i!=p&&i!=q
           &&j!=k&&j!=l&&j!=m&&j!=n&&j!=o&&j!=p&&j!=q
                 &&k!=l&&k!=m&&k!=n&&k!=o&&k!=p&&k!=q
                       &&l!=m&&l!=n&&l!=o&&l!=p&&l!=q
                             &&m!=n&&m!=o&&m!=p&&m!=q
                                   &&n!=o&&n!=p&&n!=q
                                         &&o!=p&&o!=q
                                               &&p!=q)
       return 1;
     else    return 0;     
}

int comparesum(int i,int j,int k,int l,int m,int n,int o,int p,int q)
{
    if(i+j+k==l+m+n&&i+j+k==o+p+q&&i+j+k==i+l+o
       &&i+l+o==j+m+p&&i+l+o==k+n+q&&i+l+o==i+m+q
       &&i+m+q==k+m+o)  
       return 1;
    else    return 0;   
}

void maqicalMatrix()
{
    int  i,j,k,l,m,n,o,p,q;
    for(i=1;i<=9;i++) 
     for(j=1;j<=9;j++)
       for(k=1;k<=9;k++)
         for(l=1;l<=9;l++)
          for(m=1;m<=9;m++)
            for(n=1;n<=9;n++)
              for(o=1;o<=9;o++)
                for(p=1;p<=9;p++)
                 for(q=1;q<=9;q++)
                 {
                     if(ne(i,j,k,l,m,n,o,p,q)) 
                     if(comparesum(i,j,k,l,m,n,o,p,q))
                     {
                         printf("寻找到的魔幻方阵是：\n");
                         printf("%d  %d  %d\n",i,j,k);
                         printf("%d  %d  %d\n",l,m,n);
                         printf("%d  %d  %d\n",o,p,q);  
                         printf("\n"); 
                         return;                         
                     }                
                 } 
}
int main()
{
  maqicalMatrix();
  system("PAUSE");	
  return 0;
}
