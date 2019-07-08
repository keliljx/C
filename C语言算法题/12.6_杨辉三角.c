#include<stdio.h>
int num(int i,int j);
#define N 10
main()
{
int n,i,j,k;
printf("输入要打印的行数n:(n<=N)");
scanf("%d",&n);
for(i=0;i<n;i++)
 {
 for(k=0;k<20-2*i;k++)/*因为每个数占4列,所以下一行要少打2个空格就刚好错开*/
   printf(" ");
 for(j=0;j<=i;j++)
  printf("%4d",num(i,j));
 printf("\n");
 }
}  
int num(int i,int j)//显示杨辉三角中的数
{
if(i==j||j==0)//开头和末尾的1
 return(1);
else
 return(num(i-1,j-1)+num(i-1,j));//中间的数
}
//打印杨辉三角形