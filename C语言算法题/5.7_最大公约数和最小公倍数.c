#include<stdio.h>
int a(int m,int n)			/*�����Լ��*/
{
	int min;
	if(m<=0||n<=0)
		return -1;
	if(m>n)					/*ȡ���������������С��������min*/
		min=n;
	else
		min=m;
	while(min)				
	{
		if(m%min==0&&n%min==0)	/*�ֱ��minȡ��*/
			return min;			/*�������Լ��*/
		min--;
	}
	return -1;
}
int b(int m,int n)
{
	int max;
	if(m<=0||n<=0)
		return -1;
	if(m>n)						/*��m��n������������������max*/
		max=m;
	else
		max=n;
	while(max)
	{
		if(max%m==0&&max%n==0)	/*����С������*/
			return max;
		max++;
	}
	return -1;
}
main()
{
	int m,n;
	printf("�����������������������������Լ������С��������\n");
	scanf("%d %d",&m,&n);
	printf("%d��%d�����Լ����%d\n",m,n,a(m,n));
	printf("%d��%d����С��������%d\n",m,n,b(m,n));

}