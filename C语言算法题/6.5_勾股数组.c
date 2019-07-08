#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int commonDivisor(int m,int n)
{
    int t;
    if(m<n){
        t=m;m=n;n=t;
     }
     while(m%n){
         t=m%n;
         m=n;n=t;              
     }    
     return t;
}
int main()
{
    int a,b,c,m,n,i,j,k=0,cd,s[20][3],p,t;
    for(n=1;n<=8;n++){
        for(m=n+1;m<=9;m++){
            a=2*m*n;b=m*m-n*n;c=m*m+n*n;
            cd=commonDivisor(commonDivisor(a,b),c);
            if(cd!=1)    continue;
            if(c>100)    continue;
            if(a>b)      {t=a;a=b;b=t;}
            k++;s[k][0]=a;
            s[k][1]=b;s[k][2]=c;                   
        }
    }    
    for(i=1;i<k;i++){
        p=i;
        for(j=i+1;j<=k;j++)    
            if(s[p][0]>s[j][0])    p=j;
        t=s[i][0];s[i][0]=s[p][0];s[p][0]=t;
        t=s[i][1];s[i][1]=s[p][1];s[p][1]=t;
        t=s[i][2];s[i][2]=s[p][2];s[p][2]=t;
    }
    printf("\n\n100以内的二维基本勾股数组为：\n");
    for(i=1;i<=k;i++)
        printf("(%3d,%3d,%3d),",s[i][0],s[i][1],s[i][2]);
    printf("\t共%d个\n",k);
    system("PAUSE");	
    return 0;
}
