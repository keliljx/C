#include<stdio.h>
main()
{
	int len;										/*����lenΪ�������ͱ���*/
	char *str[100];									/*�����ַ���ָ������str*/
	printf("please input a string:\n");
	gets(str);										/*gets������������ַ�����������str��*/
	len=length(str);								/*����length����*/
	printf("the string has %d characters.",len);		/*��������*/
}
int length(char *p)									/*�Զ��庯��length*/
{
	int n=0;										/*�������nΪ��������*/
	while(*p!='\0')									/*��ָ��δָ���ַ���������־ʱִ��ѭ�������*/
	{
		n++;										/*���ȼ�1*/
		p++;										/*ָ�������*/
	}
	return n;										/*�������ճ���*/
}
