#define N 20										/*���峣��*/
#include <stdio.h>									/*����ͷ�ļ�*/
void main()
{
	int i;												/*�������ͱ�����ѭ������*/
	int score,count=0;									/*�������ͱ������洢���������ֵ*/
	printf(" enter score of course number:\n");			/*��ʾ�û��������*/
	for (i=1;i<=N;i++)									/*ѭ��*/
	{
		scanf("%d",&score);							/*�����û�����������*/
		if(score<60)									/*�������С��60*/
		{
			count++;
		}
	}
	printf("the count of fail is %d\n ",count);				/*��������������*/
	return 0;
}
