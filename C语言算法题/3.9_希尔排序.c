#include<stdio.h>
void main()
{
	int a[10];                 /*�������������ֵ�һά����*/
	int i,j,k,t;               /*�������������ѭ���ı������м����*/
	printf("������10����������֮���ÿո������\n");
	for(i=0;i<10;i++)
		scanf("%d",&a[i]);     /*��������*/
	k=10/2;
	while(k>0)                 /*ϣ������*/
	{
		for(i=k;i<10;i++)
		{
			j=i-k;
			while(j>=0)
				if(a[j]>a[j+k])
				{t=a[j];a[j]=a[j+k];a[j+k]=t;j-=k;}
				else break;
		}
		k/=2;
	}
	printf("����������ְ�ϣ��������С��������Ϊ��\n");
	for(i=0;i<10;i++)
		printf("%d ",a[i]);   /*����ź��������*/
	printf("\n");
}