#include <stdio.h>
#include <stdlib.h>

void fun(int m,int n,int ar[ ][4],int * bar)
{  int i,j,x;
   for(i=0;i<m;i++)
{  x=ar[i][0];
   for (j=0;j<n;j++) if(x<ar[i][j])x=ar[i][j];
     bar[i]=x;
}
}
main()
{  int a[3][4]={{12,41,36,28},{19,33,15,27},{3,27,19,1}},b[3],i,j;
printf("ԭ�����ǣ�\n");
for(i=0;i<3;i++){
    for(j=0;j<4;j++){
                     printf("%4d",a[i][j]);
                     }
                     printf("\n");
                 }
  fun(3,4,a,b);
  printf("\n����ÿ�е����ֵ�ǣ�\n\n");
  for(i=0;i<3;i++){
  printf("��%d�е����ֵ�ǣ�%4d",i+1,b[i]);
  printf("\n");
}
  printf("\n");  
  system("PAUSE");	
  return 0;
}
