#include <stdio.h>
void order(int *p,int n)
{
	int i,t,j;
	for(i=0;i<n-1;i++)
		for(j=0;j<n-1-i;j++)
			if(*(p+j)>*(p+j+1)) 							/*�ж���������Ԫ�صĴ�С*/
			{
				t=*(p+j);
				*(p+j)=*(p+j+1);
				*(p+j+1)=t; 								/*�����м����t����ֵ����*/
			}
	printf("����������:");
	for(i=0;i<n;i++)
	{
		if(i%5==0) 										/*��ÿ��5��Ԫ�ص���ʽ���*/
			printf("\n");
		printf("%5d",*(p+i)); 								/*���������������Ԫ��*/
	}
	printf("\n");
}
main()
{
	int a[20],i,n;
	printf("����������Ԫ�صĸ���:\n");
	scanf("%d",&n); 										/*��������Ԫ�صĸ���*/
	printf("���������Ԫ��:\n");
	for(i=0;i<n;i++)
		scanf("%d",a+i); 									/*������Ԫ�ظ���ֵ*/
	order(a,n); 											/*����order����*/
}
