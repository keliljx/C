#include<stdio.h>
int search(int a[],int y,int x);/*���Զ���ĺ���search��������*/
void main()
{
	int i,x,n;  /*��������*/
	int a[10];
	printf("������10�����֣�\n");
	for(i=0;i<10;i++)
		scanf("%d",&a[i]);/*�������������*/
	printf("������Ҫ���ҵ�����");
	scanf("%d",&x);  /*���չؼ���*/
	n=search(a,10,x);/*���ú���search()���˳�����*/
	if(n<0)   /*���Ҫ�ҵ�����λ��*/
		printf("û�ҵ���Ҫ�ҵ���,��Ҫ�ҵ������ܲ��������С�\n");
	else
		printf("��Ҫ�ҵ���%d�������е�%d��Ԫ�ش���\n",x,n);
}
int search(int a[],int y,int x)/*�����õĺ���search()*/
{
	int i,f=-1;
	for(i=0;i<10;i++)
		if(x==a[i])
		{
			f=i+1;
			break;
		}
		return(f);
}
