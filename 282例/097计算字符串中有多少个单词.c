#include<stdio.h>
int main()
{
	char cString[100];									/*���屣���ַ���������*/
	int iIndex, iWord=1;								/*iWord��ʾ���ʵĸ���*/
	char cBlank;										/*��ʾ�ո�*/
	gets(cString);										/*�����ַ���*/
	if(cString[0]=='\0')									/*�ж�����ַ���Ϊ�յ����*/
	{
		printf("There is no char!\n");
	}
	else if(cString[0]==' ')								/*�жϵ�һ���ַ�Ϊ�ո�����*/
	{
		printf("First char just is a blank!\n");
	}
	else
	{
		for(iIndex=0;cString[iIndex]!='\0';iIndex++)		/*ѭ���ж�ÿһ���ַ�*/
		{
			cBlank=cString[iIndex];						/*�õ������е��ַ�Ԫ��*/
			if(cBlank==' ')								/*�ж��ǲ��ǿո�*/
			{
				iWord++;								/*��������1*/
			}
		}
		printf("%d\n",iWord);
	}
}
