#include <string.h>
#include <stdio.h>
main()
{
	int i, j = 1, n;
	float a[100], b[100], sum = 0;
	printf("\nEnter the number of players:\n");
	scanf("%d", &n); 										/*�Ӽ���������ѡ�ֵ�����*/
	for (i = 1; i <= n; i++)
	{
		printf("now player %d\n", i);
		printf("please input score:\n");
		for (; j < 5 *n + 1; j++)
		{
			scanf("%f", &a[j]); 							/*����5������ÿ�����������ķ���*/
			sum += a[j]; 									/*����ܷ���*/
			if (j % 5 == 0)									/*һλѡ����5�����и����*/
			{
				break;
			}
		}
		b[i] = sum; 										/*��ÿ��ѡ�ֵ��ִܷ浽����b��*/
		sum = 0; 										/*���ܷ�������0*/
		j++; 											/*j�Լ�*/
	}
	j = 1;
	printf("player     judgeA  judgeB  judgeC  judgeD  judgeE  total\n");
	for (i = 1; i <= n; i++)
	{
		printf("player %d", i); 								/*�������ѡ��*/
		for (; j < 5 *n + 1; j++)
		{
			printf("%8.1f", a[j]); 							/*������и�ÿ��ѡ�ֶ�Ӧ�ķ���*/
			if (j % 5 == 0)
			{
				break;
			}
		}
		printf("%8.1f\n", b[i]); 								/*���ÿ��ѡ�����õ��ܳɼ�*/
		j++;
	}
	return 0;
}
