#include <stdio.h>
#include <math.h>
#include <stdlib.h>
main()
{
	int i, j, n = 0;										/*�������Ϊ��������*/
	system("cls");
	printf("10-100֮�������:\n");
	for (i = 10; i <= 100; i++)
	{
		for (j = 2; j <= sqrt(i); j++)
		{
			if (i % j == 0) 							/*�ж��Ƿ��ܱ�����*/
				break; 								/*����ܱ��������Ͳ���Ҫ�����жϣ�����ѭ��*/
			else
			{
				if (j > sqrt(i) - 1) 
				{
					printf("%d,", i);
					n++;								/*��¼����*/
					if (n % 5 == 0) 					/*5��һ����*/
						printf("\n");
				}
				else
					continue;
			}
		}
	}
	printf("\n");
}
