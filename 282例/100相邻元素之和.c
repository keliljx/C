#include<stdio.h>
main()
{
	int a[10], b[10], i;									/*�������鼰����Ϊ��������*/
	printf("please input array a:\n");
	for (i = 0; i < 10; i++)
		scanf("%d", &a[i]);								/*����10��Ԫ�ص�����a��*/
	for (i = 1; i < 10; i++)
		b[i] = a[i] + a[i - 1];								/*������a����������Ԫ����ͷŵ�����b��*/
	for (i = 1; i < 10; i++)
	{
		printf("%5d", b[i]); 							/*������b��Ԫ�����*/
		if (i % 3 == 0)
			printf("\n");								/*ÿ���3��Ԫ�ؽ��л���*/
	}
	return 0;
}
