#include<stdio.h>
main()
{
	int i=2,n;										/*�������i��nΪ�������Ͳ�Ϊi����ֵ2*/
	float fac=1;									/*����facΪ�������Ͳ�����ֵ1*/
	printf("please input an interger>=0.\n");
	scanf("%d",&n);								/*ʹ��scanf������ȡn��ֵ*/
	if(n==0||n==1)									/*��nΪ0��1��ʱ������ײ�Ϊ1*/
	{
		printf("factorial is 1.\n");
		return 0;
	}
	while(i<=n)									/*�������������ֵ���ڵ���iʱִ��ѭ�������*/
	{
		fac=fac*i;								/*ʵ����ײ�Ĺ���*/
		i++;										/*����i�Լ�*/
	}
	printf("factorial of %d is:%.2f.\n",n,fac);			/*���n��fac���յ�ֵ*/
	return 0;
}
