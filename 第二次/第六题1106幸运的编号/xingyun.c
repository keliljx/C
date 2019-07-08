#include <stdio.h> 
#include <stdlib.h> 
#include<malloc.h> 
int main() 
{     int t,i,count,n,m;      
scanf("%d %d",&n,&m);      
int *a;     
a = (int*)malloc(sizeof(int)*n);     
for(t=0;t<n;t++)         
a[t]=1;     t=0;    //将要数的数字     
i=0;     count=0;      
while(count<n-1)     
{         
if(a[i]==1)         
{             t++;             
if(t==m)             
{                 
a[i]=0;                 
t=0;                 
count++;             
}        
 }        
 i=(i+1)%n;     
}    
 for(i=0;i<n;i++)     
{         
if(a[i]==1)         
{             
printf("%d\n",i+1);             
break;         
}     
}     
return 0;
 }