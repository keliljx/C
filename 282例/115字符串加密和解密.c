#include <stdio.h>
#include<string.h>
int main()
{
	int result = 1;
	int i;
	int count = 0;
	char Text[128] = {'\0'};								/*����һ�������ַ�����*/
	char cryptograph[128] = {'\0'};						/*����һ�������ַ�����*/
	while (1)
	{
		if (result == 1)									/*����Ǽ�������*/
		{
			printf("������Ҫ���ܵ����ģ�\n");			/*����ַ���*/
			scanf("%s", &Text);						/*��ȡ���������*/
			count = strlen(Text);
			for(i=0; i<count; i++)						/*��������*/
			{
				cryptograph[i] = Text[i] + i + 5;			/*���ü����ַ�*/
			}
			cryptograph[i] = '\0';						/*�����ַ����������*/
			/*���������Ϣ*/
			printf("���ܺ�������ǣ�%s\n",cryptograph);
		}
		else if(result == 2)								/*����ǽ����ַ���*/
		{
			count = strlen(Text);
			for(i=0; i<count; i++)						/*���������ַ���*/
			{
				Text[i] = cryptograph[i] - i - 5;			/*���ý����ַ�*/
			}
			Text[i] = '\0';								/*�����ַ����������*/
			/*���������Ϣ*/
			printf("���ܺ�������ǣ�%s\n",Text);
		}
		else if(result == 3)								/*������˳�ϵͳ*/
		{
			break;									/*����ѭ��*/
		}
		else
		{
			printf("��������ȷ�������\n");			/*����ַ���*/
		}
		/*����ַ���*/
		printf("����1�����µ����ģ�����2�Ըռ��ܵ����Ľ��н��ܣ�����3�˳�ϵͳ��\n");	
		printf("�������������\n");						/*����ַ���*/
		scanf("%d", &result);							/*��ȡ����������ַ�*/
	}
	return 0;											/*�������*/
}
