#include <stdio.h>
#include <stdlib.h>
int main()
{
   int x[4][4],n,i,j;
   printf("������һ��4*4�����飺\n"); 
   for(i=0;i<4;i++){
     for(j=0;j<4;j++) {
        scanf("%d",&x[i][j]);
     }
   }
     printf("������������ǣ�\n");
     for(i=0;i<4;i++){
        for(j=0;j<4;j++) {
            printf("%3d",x[i][j]);;
        }
        printf("\n");
     }
     printf("����������������������ǣ�\n");
     for(i=0;i<4;i++){
        for(j=0;j<=i;j++) 
          printf("%3d",x[i][j]);
          printf("\n");
      }
  system("PAUSE");	
  return 0;
}
