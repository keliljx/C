#include <stdio.h>
#include <string.h>
main()
{
	char str[50];
	printf("please input string:\n");
	gets(str); 										/*�����ַ���*/
	strlwr(str);										/*����strlwr������ʵ�ִ�д��ĸתСд��ĸ*/
	printf(str); 										/*��ת����Ľ�����*/
	printf("\n");
}
