#include <stdio.h>
main()
{
	int i, j, count;
	puts("the result is:\n");
	printf("time  red ball  white ball  black ball\n");
	count = 1;
	for (i = 0; i <= 3; i++)										/*����������Χ0��3֮��*/
	{
		for (j = 0; j <= 3; j++)									/*�����������Χ0��3֮��*/
		{
			if ((8-i - j) <= 6) 									/*�ж�Ҫȡ��ɫ��������Ƿ���6������*/
				printf("%3d%8d%9d%10d\n", count++, i, j, 8-i - j); 	/*���������ɫ�������*/
		}
	}
	return 0;
}
