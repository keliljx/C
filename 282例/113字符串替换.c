#include<stdio.h>
char *replace(char *s1, char *s2, int pos) 						/*�Զ����������*/
{
	int i, j;
	i = 0;
	for (j = pos; s1[j] != '\0'; j++)								/*��ԭ�ַ���ָ��λ�ÿ�ʼ���*/
	if (s2[i] != '\0')
	{
		s1[j] = s2[i]; 										/*�������������ŵ�ԭ�ַ�����*/
		i++;
	}
	else
		break;
	return s1; 											/*���������ַ��������*/
}
main()
{
	char string1[100], string2[100]; 							/*���������ַ�������*/
	int position;
	printf("\nPlease input original string:");
	gets(string1); 											/*�����ַ���1*/
	printf("\nPlease input substitute string:");
	gets(string2); 											/*�����ַ���2*/
	printf("\nPlease input substitute position:");
	scanf("%d", &position); 								/*����Ҫ�滻��λ��*/
	replace(string1, string2, position); 						/*�����滻����*/
	printf("\nThe final string:%s\n", string1); 				/*��������ַ���*/
	return 0;
}
