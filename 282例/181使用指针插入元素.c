#include<stdio.h>
#define N 10
void insert(int *a, int n, int x)								/*����Ԫ�ص��Զ������*/
{
	int*p, *q;											/*����ָ�����*/
	for(p=a;p<a+n; p++)								/*��������Ԫ��*/
	{
		if(*p>x)										/*�ҵ�Ҫ�����λ��*/
		{
			q=p;										/*��¼Ҫ�����λ��*/
			break;									/*����ѭ��*/
		}
	}
	for(p=a+n;p>=q;p--)								/*������λ��֮�����������*/
		*p=*(p-1);	
	*q=x;											/*����*/
}
main()
{
	int i, a[N+1],an;									/*��������������*/
	int *p;											/*����ָ�����*/
	printf("Input 10 seriate integer :\n ");
	for (i = 0; i < N; i++)
		scanf("%d", &a[i]);								/*��������Ԫ��*/
	printf("input inserting data: ");
	scanf("%d", &an);									/*����Ҫ�������*/
	insert(a,N,an);										/*���в������*/
	for(p=a;p<a+N+1;p++)
	{
		printf("%3d",*p);								/*�������Ԫ�غ������*/
	}
}
