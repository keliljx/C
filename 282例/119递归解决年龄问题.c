#include<stdio.h>
int age(int n)											/*�Զ��庯��age*/
{
	int f;
	if(n==1)
	f=10;											/*��n����1ʱ��f����10*/
	else
	f=age(n-1)+2;										/*�ݹ����age����*/
	return f;											/*��fֵ����*/
}
main()
{
	int i,j;											/*�������i��jΪ��������*/
	printf("Do you want to know whose age?please input:\n");
	scanf("%d",&i);									/*����i��ֵ*/
	j=age(i);											/*���ú���age������*/
	printf("the age is %d",j);								/*��������������*/
    printf("\n");
}
