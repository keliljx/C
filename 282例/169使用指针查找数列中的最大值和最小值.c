#include<stdio.h>
void max_min(int a[], int n, int *max, int *min)
{
	int *p;
	*max =  *min =  *a;									/*��ʼ�����ֵ��Сֵָ�����*/
	for (p = a + 1; p < a + n; p++)
	if (*p >  *max)
		*max =  *p;										/*���ֵ*/
	else if (*p <  *min)
		*min =  *p;										/*��Сֵ*/
	return 0;
}

main()
{
	int i, a[10];
	int max, min;
	printf("Input 10 integer numbers you want to operate:\n ");
	for (i = 0; i < 10; i++)
		scanf("%d", &a[i]);										/*��������Ԫ��*/
	max_min(a, 10, &max, &min);								/*�������ֵ����Сֵ*/
	printf("\nThe maximum number is: %d\n", max);				/*������ֵ*/
	printf("The minimum number is: %d\n", min);					/*�����Сֵ*/
	getch();
}
