#include <stdio.h>
#include<string.h>
main()
{
	char str1[30], str2[30],  *p1,  *p2;
	printf("please input string1:");
	gets(str1); 										/*�Ӽ����������ַ���1*/
	printf("please input string2:");
	gets(str2); 										/*�Ӽ����������ַ���2*/
	p1 = strdup(str1); 									/*p1ָ�����ַ���1�ĵ�ַ*/
	p2 = strdup(str2); 									/*p2ָ�����ַ���2�ĵ�ַ*/
	printf("string1:%s\nstring2:%s", p1, p2); 			/*����ָ������ַ���*/
	printf("\n");
	return 0;
}
