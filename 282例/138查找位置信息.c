#include <string.h>
#include <stdio.h>
main()
{
	char str1[30], str2[30], str3[30], str4[30],  *p;
	int pos;
	printf("please input string1:");
	gets(str1); 											/*�Ӽ����������ַ���1*/
	printf("please input string2:");
	gets(str2); 											/*�Ӽ����������ַ���2*/
	pos = strspn(str1, str2); 									/*���ú���strspn�ҳ���ͬ��λ��*/
	printf("the position you want to find is:%d\n", pos);
	printf("please input string3:");
	gets(str3); 											/*�Ӽ����������ַ���3*/
	printf("please input string4:");
	gets(str4); 											/*�Ӽ����������ַ���4*/
	p = strstr(str3, str4); 									/*���ú���strstr�鿴str3���Ƿ����str4*/
	if (p)
	{
		printf("str3 include str4\n");
	}
	else
	{
		printf("can not find str4 in str3!");
	}
	printf("\n");
	return 0;
}
