#include <stdio.h>
main()
{
	int i, num, k;												/*��������*/
	int a[10]={10,11,27,25,34,56,18,37,45,16};					/*��ʼ��һ������*/
	k=11;													/*Ϊ������ֵ*/
	printf("Please input the member which you want to find:\n");
	scanf("%d",&num);										/*����һ����*/
	for (i=0; i<10; i++)											/*ִ��ѭ��*/
	{
		if(num==a[i])											/*�ж��Ƿ������Ԫ��ֵ���*/
			k=i;												/*��¼�±�λ��*/
	}
	if(k!=11)													/*���ݽ�����*/
		printf("The member you find is in the array \n");
	else
		printf("Have not found the number\n");
}
