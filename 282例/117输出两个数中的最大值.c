#include<stdio.h>

int max(int x,int y)										/*����һ�������ֵ�ĺ���*/
{
	int z;											/*����һ������*/
	z=x>y?x:y;										/*���������е����ֵ*/
	return z;											/*�����������ֵ*/
}

int main()
{
	int a, b, c;											/*����3������*/
	printf("input two number:\n");						/*�����ʾ�ַ���*/
	scanf("%d%d",&a,&b);								/*���ռ����������������*/
	c=max(a,b);										/*���ú��������ֵ*/
	printf("max is %d\n",c);								/*������ֵ*/
	return 0;											/*�������*/
}
