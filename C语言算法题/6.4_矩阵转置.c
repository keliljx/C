#include <stdio.h>
#include <stdlib.h>
int main()
{
  int a[4][5],b[5][4];
  printf("请输入一个4*5的矩阵：\n");
  int i,j;
    for(i=0;i<4;i++){
        for(j=0;j<5;j++)
        {
            scanf("%d",&a[i][j]);                
        }
        }
   for(i=0;i<5;i++){
        for(j=0;j<4;j++)
            b[i][j]=a[j][i]; 
   }   
  printf("转置后的矩阵是：\n");
  for(i=0;i<5;i++)
  {
        for(j=0;j<4;j++)
        {
            printf("%d  ",b[i][j]);                
        }
        printf("\n");
   }
    system("PAUSE");	
  return 0;
}
