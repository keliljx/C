#include <stdio.h>
#include <stdlib.h>
int main()
{
   int x[4][4],n,i,j;
   printf("请输入一个4*4的数组：\n"); 
   for(i=0;i<4;i++){
     for(j=0;j<4;j++) {
        scanf("%d",&x[i][j]);
     }
   }
     printf("你输入的数组是：\n");
     for(i=0;i<4;i++){
        for(j=0;j<4;j++) {
            printf("%3d",x[i][j]);;
        }
        printf("\n");
     }
     printf("你输入数组的下三角置数是：\n");
     for(i=0;i<4;i++){
        for(j=0;j<=i;j++) 
          printf("%3d",x[i][j]);
          printf("\n");
      }
  system("PAUSE");	
  return 0;
}
