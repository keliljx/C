#include<stdio.h>
int main()
{
	int a[3][3];								/*����һ��3��3�е�����*/
	int i,j,sum=0;								/*����ѭ�����Ʊ����ͱ������ݱ���sum*/
	printf("please input:\n");
	for(i=0;i<3;i++)							/*����ѭ�����ж�����Ԫ�ؽ��и�ֵ*/
	{
		for(j=0;j<3;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
	for(i=0;i<3;i++)							/*ʹ��ѭ�����м���Խ��ߵ��ܺ�*/
	{
		for(j=0;j<3;j++)
		{
			printf("%5d",a[i][j]);
			sum=sum+a[i][j];					/*�������ݵ��ۼӼ���*/
		}
		printf("\n");
	}
	printf("the result is :%d\n",sum);				/*������Ľ��*/
	return 0;
}
