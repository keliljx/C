#include "stdio.h"									/*����ͷ�ļ�*/
#include "string.h"
#include "conio.h"
sort(char *strings[], int n)
{
	char *temp;									/*�����ַ���ָ�����*/
	int i, j;										/*�������ͱ���*/
	for (i = 0; i < n; i++)							/*���ѭ��*/
	{
		for (j = i + 1; j < n; j++)
		{
			if (strcmp(strings[i], strings[j]) > 0)		/*�Ƚ������ַ�*/
			{
				temp = strings[i];					/*�����ַ�λ��*/
				strings[i] = strings[j];
				strings[j] = temp;
			}
		}
	}
}
void main()
{
	int n = 5;
	int i;
	char **p;										/*ָ��ָ���ָ�����*/
	char *strings[] =
	{
		"��XX", "ǮXX", "��XX", "��XX", "��XX"
	};											/*��ʼ���ַ�������*/
	p = strings;									/*ָ��ָ�������׵�ַ*/
	printf("����ǰ������:\n");
	for(i=0;i<n;i++)
	{
		printf("%s\n",strings[i]);
	}
	sort(p, n);										/*���������Զ������*/
	printf("����������:\n");
	for (i = 0; i < n; i++)							/*ѭ���������������Ԫ��*/
	{
		printf("%s\n", strings[i]);
	}
	getch();
}