#include<stdio.h>
int main()
{
	int iSelect=1;											/*�����������ʾ�˵���ѡ��*/
	while(iSelect!=0)										/*����������ѭ����ʾ�˵�*/
	{	/*��ʾ�˵�����*/
		printf("---------Menu---------\n");
		printf("----Sell----------1\n");
		printf("----Buy-----------2\n");
		printf("----ShowProduct---3\n");
		printf("----Out-----------0\n");
		scanf("%d",&iSelect);								/*����˵���ѡ��*/
		switch(iSelect)										/*ʹ��switch��䣬��������������Ӧ�Ĵ���*/
		{
			case 1:										/*ѡ���һ��˵������*/
				printf("you are buying something into store\n");
				break;
			case 2:										/*ѡ��ڶ���˵������*/
				printf("you are selling to consumer\n");
				break;
			case 3:										/*ѡ�������˵������*/
				printf("checking the store\n");
				break;
			case 0:										/*ѡ���˳���˵������*/
				printf("the Program is out\n");
				break;
			default:										/*Ĭ�ϴ���*/
				printf("You put a wrong selection\n");
				break;
		}
	}
	return 0;
}
