#include<stdio.h>
#include<string.h>
#define MAXN 100
int a[MAXN][MAXN];
int main()
{
	int n,i,j,t=0;
	scanf("%d",&n);
	memset(a,0,sizeof(a));//����
	t=a[i=0][j=n-1]=1;//��0�е�n-1��������ʼ1
	while(t<n*n)//�����е���������n*n
	{
		while(i+1<n && !a[i+1][j])//���¸�ֵ
			a[++i][j]=++t;
		while(j-1>=0&&!a[i][j-1])//����ֵ
			a[i][--j]=++t;
		while(i-1>=0&&!a[i-1][j])//���ϸ�ֵ
			a[--i][j]=++t;
		while(j+1<n&&!a[i][j+1])//����ֵ
			a[i][++j]=++t;
	}
	for(i=0;i<n;i++)//������ά���飬���
	{
		for(j=0;j<n;j++)
			printf("%4d",a[i][j]);
		printf("\n\n");
	}
	return 0;

}
