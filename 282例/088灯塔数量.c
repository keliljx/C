#include<stdio.h>
main()
{
	int n = 1, m, sum, i; 								/*�������Ϊ��������*/
	while (1)
	{
		m = n; 										/*m�洢һ¥�Ƶ�����*/
		sum = 0;
		for (i = 1; i < 8; i++)
		{
			m = m * 2;								/*ÿ��¥�Ƶ���������һ���2��*/
			sum += m; 								/*�������һ¥��Ƶ�����*/
		}
		sum += n; 									/*����һ¥�Ƶ�����*/
		if (sum == 765)								/*�жϵƵ��������Ƿ�ﵽ765*/
		{
			printf("the first floor has %d\n", n); 			/*���һ¥�Ƶ�����*/
			printf("the eight floor has %d\n", m); 			/*�����¥�Ƶ�����*/
			break; 									/*����ѭ��*/
		}
		n++; 										/*�Ƶ�������1�������´�ѭ��*/
	}
	return 0;
}
