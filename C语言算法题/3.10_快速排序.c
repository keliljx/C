#include<stdio.h>
int p(int a[],int low,int high);/*��������p*/
void q(int a[],int low,int high);/*��������q*/
void main()
{
	int a[10];         /*�������������ֵ�һά����*/
	int i;             /*�������������ѭ���ı���*/
	printf("������10��������֮���ÿո����\n");
	for(i=0;i<10;i++)
		scanf("%d",&a[i]);/*�������������洢������a��*/
	q(a,0,9);           /*���ú���q*/
	printf("����������С��������Ϊ\n");
	for(i=0;i<10;i++)
	printf("%d ",a[i]);  /*����ź��������*/
	printf("\n");
}
int p(int a[],int low,int high) /*����p*/
{
	int key=a[low],p;
	while(low<high)
	{
		while(low<high && a[high]>=key)
			--high;
		p=a[low];a[low]=a[high];a[high]=p;
		while(low<high && a[low]<=key)
			++low;
		p=a[high];a[high]=a[low];a[low]=p;
	}
		a[low]=key;
		return low;
}

void q(int a[],int low,int high) /*����q*/
{
	int j;
	if(low<high)
	{
		j=p(a,low,high);      /*���ú���p*/
		q(a,low,j-1);         /*���ú���q*/
		q(a,j+1,high);        /*���ú���q*/
	}
}
