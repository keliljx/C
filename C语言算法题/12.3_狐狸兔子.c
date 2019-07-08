#include <stdio.h> 
void main() 
{ 
 int i,n,a[10]; 
 for(i=0;i<10;i++) 
 a[i]=0;						/*每一个洞先置0,表示没有狐狸进入过*/ 
 n=0; 
 for(i=1;i<=1000;i++) 
 {n=(n+i)%10; 
 a[n]=1;						/*有狐狸进过的洞置1 */ 
 } 
 printf("聪明的兔子可能躲的洞号为：\n");  
 for(i=0;i<10;i++) 
 if(a[i]==0) printf("%d  ",i);	/* 列出所有为0的洞号 */ 
 printf("\n");
}
