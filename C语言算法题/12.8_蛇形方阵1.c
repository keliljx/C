#include<stdio.h>
#include<string.h>
#define MAX 100
int a[MAX][MAX];
int main()
{
	int i,j,n,k=0,t=1;
	scanf("%d",&n);				//��������������n
	memset(a,0,sizeof(a));		//����a����
	for(i=n-1;i>=0;i--)			//������
	{
		if(k==0)				//���ҵ���˳�����ε���1������Ԫ��
		{
			for(j=n-1;j>=0;j--)
				a[i][j]=t++;
			k=1;
		}
		else					//������˳�����ε���1������Ԫ��
		{
			for(j=0;j<=n-1;j++)
				a[i][j]=t++;
			k=0;
		}
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
			printf("%4d",a[i][j]);//��ӡȫ������Ԫ��
		printf("\n\n");
	}
return 0;
}