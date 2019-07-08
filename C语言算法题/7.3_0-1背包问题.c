#include<stdio.h>
int x[100];            /*��¼��Ʒ���״̬*/
int pValue[100]={0};   /*��Ʒ�ĵ���*/
int pWeight[100]={0};  /*��Ʒ������*/

void knapsack0(int n,int flag,int c,int *price)  /*��ȡ����ֵ*/
{
	int i, j,p;
	if(bound(n,c)) return;      /*�ж��Ƿ񳬳����ĳ�����*/
	if(n==flag)
	{
		p=getvalue(n);			/*��ȡ������Ʒ���ܼ�ֵ*/
		if(*price<p) 
			*price=p;
		return;
	}
	for(i=0;i<=1;i++)
	{
		x[n]=i;							/*���÷��ñ�ʶ*/
		knapsack0(n+1,flag,c,price);	/*�ݹ����*/
	}
	
}
void knapsack1(int n,int flag,int c,int *price)
{
	int i, j,p;
	
	if(bound(n,c)) return;			/*�ж��Ƿ񳬳����ĳ�����*/
	if(n==flag)
	{
		p=getvalue(n);				/*��ȡ������Ʒ�ܼ�ֵ*/
		if(*price==p)				/*���������ֵ��ȣ������������Ʒ*/
		{
			printf("\n\n�������ƷΪ��\n");
			for(j=0;j<n;j++)
				if(x[j]==1)
				{
					printf("��Ʒ��ţ�%d\n",j);		/*�����Ʒ���*/
					printf("������ %d kg\n",pWeight[j]);		/*�����Ʒ����*/
					printf("�۸� %d $\n\n",pValue[j]);		/*�����Ʒ�۸�*/
				}
		}
		return;
	}
	for(i=0;i<=1;i++)
	{
		x[n]=i;
		knapsack1(n+1,flag,c,price);				/*�ݹ����*/
	}
	
}

int bound(int n,int c)		/*������Ʒ�����Ƿ��أ����ط���1�����򷵻�0*/
{
	int i,w=0;
	for(i=0;i<n;i++)
		w=w+x[i]*pWeight[i];	/*���ݰ�����Ʒ��������*/
	if (w>c) return 1;			/*����*/
	else return 0;
}

int getvalue(int n)			/*������Ʒ�ܼ�ֵ*/
{
	int i,v=0;
	for(i=0;i<n;i++)
		v=v+x[i]*pValue[i];		/*���ݰ�����Ʒ�����ֵ*/
	return v;
	
}
main()
{
	int i,n,c;
	int price=0;
	printf("������Ʒ����: \n");
	scanf("%d",&n);
	printf("���������������:\n");
	scanf("%d",&c);
	printf("����ÿ����Ʒ������\n");
	for(i=0;i<n;i++)
		scanf("%d",&pWeight[i]);
	printf("����ÿ����Ʒ�ļ�ֵ\n");
	for(i=0;i<n;i++)
		scanf("%d",&pValue[i]);	
	knapsack0(0,n,c,&price);			/*��ȡ���ܵ�����ֵ*/
	printf("����ֵΪ��%d",price);
	
	knapsack1(0,n,c,&price);			/*���������Ʒ*/
}