#include<stdio.h>
main()
{
	int a[5], i, temp; 									/*�������鼰����Ϊ��������*/
	printf("please input array a:\n");
	for (i = 0; i < 5; i++)								/*�����������Ԫ��*/
		scanf("%d", &a[i]);
	printf("array a:\n");
	for (i = 0; i < 5; i++)								/*�������е�Ԫ��������*/
		printf("%d ", a[i]);
	printf("\n");
	for (i = 0; i < 2; i++)								/*��������Ԫ�ص�ǰ��λ�û���*/
	{
		temp = a[i]; 									/*Ԫ��λ�û����Ĺ��̽����м����temp*/
		a[i] = a[4-i];
		a[4-i] = temp;
	}
	printf("Now array a:\n");
	for (i = 0; i < 5; i++)								/*��ת����������ٴ����*/
		printf("%d ", a[i]);
}
