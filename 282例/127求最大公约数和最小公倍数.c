#include <stdio.h>
int hf(int u,int v)
{
	int t,r;										/*������������*/
	if(v>u)										/*�ж���������С*/
	{t=u;u=v;v=t;}								/*ʹu����v*/
	while((r=u%v)!=0)								/*�����Լ��*/
	{
		u=v;
		v=r;
	}
	return(v);										/*�������Լ��*/
}
int ld(int u,int v, int h)
{
	return(u*v/h);									/*����С������*/
}
main()
{
	int u, v, h, l;									/*��������*/
	printf("input two integer number:\n");				/*����ַ���*/
	scanf("%d%d",&u,&v);							/*������������*/
	h=hf(u,v);									/*���������Լ�����Զ��庯��*/
	l=ld(u,v,h);									/*��������С���������Զ��庯��*/
	printf("���Լ��Ϊ�� %d\n",h);				/*������Լ��*/
	printf("��С������Ϊ�� %d\n",l);				/*�����С������*/
}
