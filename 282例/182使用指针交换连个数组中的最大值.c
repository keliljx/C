#include <stdio.h>
#define N 5
*max(int *a, int n)									/*�Զ��庯�������������ֵ��ַ*/
{
	int *p, *q;									/*����ָ�����*/
	q=a;											/*��ȡ�׵�ַ*/
	for(p=a+1;p<a+n;p++)							/*�жϲ������ֵ*/
	{
		if(*p>*q)
			q=p;									/*�����ֵ��ַ������q��*/
	}
	return q;										/*�������ֵ��ַ*/
}
swap(int *pa, int *pb)								/*����������ֵ���Զ��庯��*/
{
	int temp;										/*�������*/
	temp=*pa;									/*���н���*/
	*pa=*pb;
	*pb=temp;
}
main()
{
	int a[N], b[N];									/*������������*/
	int *pa, *pb, *p;								/*����ָ�����*/
	printf("input array a with 5 element\n");
	for(p=a;p<a+N;p++)							/*��������Ԫ��*/
	{
		scanf("%d",p);
	}
	printf("input array b with 5 element\n");
	for(p=b;p<b+N;p++)							/*��������b��Ԫ��*/
	{
		scanf("%d",p);
	}
	pa=max(a,N);									/*��ȡ����a�е����ֵ��ַ*/
	pb=max(b,N);									/*��ȡ����b�е����ֵ��ַ*/
	printf("The max numbers are %d and %d\n",*pa,*pb);
	swap(pa,pb);									/*��������Ԫ��ֵ*/
	printf("now a: ");
	for(p=a;p<a+N;p++)							/*�������*/
	{
		printf ("%3d",*p);
	}
	printf("\nnow b: ");
	for(p=b;p<b+N;p++)							/*�������*/
	{
		printf ("%3d",*p);
	}
	printf("\n");
}
