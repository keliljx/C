#include<stdio.h>
int num(int i,int j);
#define N 10
main()
{
int n,i,j,k;
printf("����Ҫ��ӡ������n:(n<=N)");
scanf("%d",&n);
for(i=0;i<n;i++)
 {
 for(k=0;k<20-2*i;k++)/*��Ϊÿ����ռ4��,������һ��Ҫ�ٴ�2���ո�͸պô�*/
   printf(" ");
 for(j=0;j<=i;j++)
  printf("%4d",num(i,j));
 printf("\n");
 }
}  
int num(int i,int j)//��ʾ��������е���
{
if(i==j||j==0)//��ͷ��ĩβ��1
 return(1);
else
 return(num(i-1,j-1)+num(i-1,j));//�м����
}
//��ӡ���������