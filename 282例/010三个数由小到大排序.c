#include <stdio.h>
main()
{
	int a, b, c, t;									/*�����ĸ��������ͱ���a��b��c��t*/
	printf("please input a,b,c:\n");						/*˫��������ͨ�ַ�ԭ�����������*/
	scanf("%d%d%d", &a, &b, &c);					/*��������������*/
	if (a > b)										/*���a����b�������м����tʵ��a��bֵ����*/
	{
		t = a;
		a = b;
		b = t;
	}
	if (a > c)										/*���a����c�������м����tʵ��a��cֵ����*/
	{
		t = a;
		a = c;
		c = t;
	}
	if (b > c)										/*���b����c�������м����tʵ��b��cֵ����*/
	{
		t = b;
		b = c;
		c = t;
	}
	printf("the order of the number is:\n");
	printf("%d,%d,%d", a, b, c);						/*���������a,b,c��ֵ˳�����*/
}
