#include<stdio.h>
int isprime(int num)								/*�Զ����ж������ĺ���*/
{
	int flag=1,i;									/*�������*/
	for(i=2;i<=num/2;i++)							/*ѭ��*/
		if(num%i==0)								/*�ж��Ƿ�������*/
			flag=0;								/*��������������*/
	return(flag);									/*�����жϽ��*/
}
main()
{ 
	int n;											/*��������*/
	printf("input an integer:");							/*����Ļ�������ʾ�ַ���*/
	scanf("%d",&n);									/*����һ���������*/
	if(isprime(n))										/*�����Զ��庯��*/
		printf("%d is a prime",n);						/*������*/
	else
		printf("%d is not a prime",n);
	printf("\n");										/*����*/
}
