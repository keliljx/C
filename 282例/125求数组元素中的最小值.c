#include <stdio.h>
int min(int array[20],int n)
{
	int m,i;
	m = array[0];										/*Ϊ��������ֵ*/
	for (i = 1; i < n; i++)								/*�ҳ���������С����*/
	{
		if (array[i] < m)
		{
			m= array[i];								/*����С����������*/
		}
	}
	return (m);									/*������С��*/
}
main()
{
	int a[20], m, n,i; 									/*�������鼰������������Ϊ��������*/
	printf("please input the counts of elements:\n");
	scanf("%d", &n); 									/*����Ҫ�����Ԫ�ظ���*/
	printf("please input the element:\n");
	for (i = 0; i < n; i++)								/*��������*/
	{
		scanf("%d", &a[i]);
	}
	m=min(a,n);										/*���ú�������������С��*/
	printf("the min number is:%3d\n", m);
	return 0;
}
