#include "stdio.h"
#include "string.h"
#include "conio.h"
sort(char *strings[], int n)								/*���ַ�������*/
{
	char *temp;
	int i, j;
	for (i = 0; i < n; i++)
	{
		for (j = i + 1; j < n; j++)
		{
			if (strcmp(strings[i], strings[j]) > 0)			/*�Ƚ��ַ���С������λ��*/
			{
				temp = strings[i];
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
	char *strings[] =
	{
		"C language", "Basic", "World wide", "Hello world",
		"One world,one dream!"
	};												/*�����ַ�������*/
	sort(strings, n);									/*����*/
	for (i = 0; i < n; i++)
		printf("%s\n", strings[i]);
	getch();
}
