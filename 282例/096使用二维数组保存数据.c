#include<stdio.h>
int main()
{
	int a[2][3];									/*��������*/
	int i,j;										/*���ڿ���ѭ��*/
	for(i=0;i<2;i++)								/*�Ӽ���Ϊ����Ԫ�ظ�ֵ*/
	{
		for(j=0;j<3;j++)
		{
			printf("a[%d][%d]=",i,j);
			scanf("%d",&a[i][j]);					/*�������Ԫ��*/
		}
	}
	printf("�����ά����\n");						/*��Ϣ��ʾ*/
	for(i=0;i<2;i++)
	{
		for(j=0;j<3;j++)
		{
			printf("%d\t",a[i][j]);					/*������*/
		}
		printf("\n");								/*ʹԪ�ط�����ʾ*/
	}
	return 0;
}
