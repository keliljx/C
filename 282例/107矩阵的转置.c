#include<stdio.h>
main()
{
  int i,j,i1,j1,a[101][101],b[101][101];					/*����������������ͺ���������*/
  printf("please input the number of rows(<=100)\n");		
  scanf("%d",&i1);								/*��������*/
  printf("please input the number of columns(<=100)\n");
  scanf("%d",&j1);								/*��������*/
  printf("please input the element\n");
  for(i=0;i<i1;i++)								/*��������*/
  for(j=0;j<j1;j++)								/*��������*/
  scanf("%d",&a[i][j]);								/*���������е�Ԫ��*/
  printf("array a:\n");								/*������������Զ�ά�������ʽ���*/
  for(i=0;i<i1;i++)								/*�������������*/
  {
    for(j=0;j<j1;j++)								/*�������������*/
    printf("\t%d",a[i][j]);							/*���Ԫ��*/
    printf("\n");									/*ÿ���һ��Ԫ�ؽ��л���*/
  }
  for(i=0;i<i1;i++)
  for(j=0;j<j1;j++)
  b[j][i]=a[i][j];									/*��a�����i��j��Ԫ�ظ���b�����j��i��ʵ�����л���*/
  printf("array b:\n");								/*���������b�������*/
  for(i=0;i<j1;i++)								/*b�����������ֵΪa��������*/
  {
    for(j=0;j<i1;j++)								/*b�����������ֵΪa��������*/
    printf("\t%d",b[i][j]);							/*���b����Ԫ��*/
    printf("\n");									/*ÿ���һ�н��л���*/
  }
} 
