#include <stdio.h>
#include <stdlib.h>
# define N 4
void sort(int a[][N])
{  int i,j,k,t;
   for(i=0;i<N;i++)
   for(j=0;j<N-1;j++)
   for(k=j+1;k<N;k++)
   /*判断行下标是否为偶数来确定按升序或降序来排序*/
   if((i%2==1)?a[i][j]<a[i][k]:a[i][j]>a[i][k])
   { t=a[i][j];
     a[i][j]=a[i][k];
     a[i][k]=t;
   }
}
void outarr(int a[N][N])
{
   int i,j;
   for(i=0;i<N;i++){
       for(j=0;j<N;j++){
       printf("%3d",a[i][j]);
       } 
       printf("\n");
   } 
}
int main()
{ int a[N][N]={{2,3,4,1},{8,6,5,7},{11,12,10,9},{15,14,16,13}};
  printf("原始的数组如下：\n");
  outarr(a);/*以矩阵的形式输出二维数组*/
  sort(a);
  printf("排序后的数组矩阵如下：\n");
  outarr(a);
  system("PAUSE");	
  return 0;
}
