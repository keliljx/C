#include<stdio.h>
#include<string.h>
void insert (char s[],  char t,  int i)					/*�Զ��庯��insert*/
{
	char string[100];								/*��������string��Ϊ�м����*/
	if (!strlen(s))
		string[0]=t;								/*��s���鳤��Ϊ0����ֱ�ӽ�t�������ݸ��Ƶ�s��*/
	else										/*�����Ȳ�Ϊ�գ�ִ���������*/
	{
		strncpy (string,s,i);							/*��s�����е�ǰi���ַ����Ƶ�string��*/
		string[i]=t;
		string[i+1]='\0';
		//strcat (string,t) ;							/*��t���ַ������ӵ�string*/
		strcat (string,(s+i));							/*��s��ʣ���ַ������ӵ�string*/
		strcpy (s,string);							/*��string���ַ������Ƶ�s��*/
	}
}
main ()
{
	char str1[100],c;								/*����str1��str2�����ַ�������*/
	int position;									/*�������positionΪ��������*/
	printf("please input str1:\n");
	gets(str1);									/*gets�������һ���ַ���*/
	printf("please input a char:\n");
	scanf("%c",&c);								/*scanf�������һ���ַ�*/
	printf("please input position:\n");
	scanf("%d",&position);							/*�����ַ��������λ��*/
	insert(str1,c,position);							/*����insert����*/
	puts(str1);									/*������յõ����ַ���*/
}
