#include<stdio.h>
char del(char s[],int pos,int len)					/*�Զ���ɾ������*/
{
	int i;
	for(i=pos+len-1;s[i]!='\0';i++,pos++)				/*i��ֵΪָ��ɾ�����ֺ�ĵ�һ���ַ�*/
		s[pos-1]=s[i];								/*��ɾ�����ֺ���ַ����δ�ɾ�����ֿ�ʼ����*/
	s[pos-1]='\0';									/*�����µõ����ַ�������ַ���������־*/
	return s;										/*�����µõ����ַ���*/
}
main()
{
	char str[50];									/*�����ַ�������*/
	int position;
	int length;
	printf("\nPlease input string:");
	gets(str);										/*ʹ��gets��������ַ���*/
	printf("\nPlease input delete position:");
	scanf("%d",&position);							/*����Ҫɾ����λ��*/
	printf("\nPlease input delete length:");
	scanf("%d",&length);							/*����Ҫɾ���ĳ���*/
	del(str,position,length);							/*����ɾ������*/
	printf("\nThe final string:%s\n",str);				/*���µõ����ַ������*/
}
