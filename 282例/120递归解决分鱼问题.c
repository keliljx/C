#include<stdio.h>
int sub(int n) 											/*���庯���ݹ����������*/
{
	if (n == 1)										/*��n����1ʱ�ݹ����*/
	{
		static int i = 0;
		do
		{
			i++;
		}
		while (i % 5 != 0);
		return (i + 1);									/*5��ƽ�ֺ���һ��*/
	}
	else
	{
		int t;
		do
		{
			t = sub(n - 1);
		}
		while (t % 4 != 0);
		return (t / 4 * 5+1);
	}
}
main() 
{ 
	int total; 
	total=sub(5); 										/*���õݹ麯��*/
	printf("the total number of fish is %d\n",total); 
	return 0;
}
