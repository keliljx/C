#include <stdio.h>
#include <string.h>
#define MAXN 100+10
int a[MAXN];
int main()
{
	int i,j,n,k,first=1;
	memset(a,0,sizeof(a));//������a����
	printf("����Ƶ�����n������k��\n");
	scanf("%d%d",&n,&k);
	printf("�������ŵĵȵı�ţ�\n");
	for(i=1;i<=k;i++)//k����
		for(j=1;j<=n;j++)//n����
			if(j%i==0)
				a[j]=!a[j];//ȡ��0��1,1��0
			for(i=1;i<=n;i++)
				if(a[i])//��a[j]��1˵������
				{
					if(first)
						first=0;//�ж��ǲ��ǵ�һ�����ݣ��ǵ�һ������ֱ�����i�����Ƶı��
					else 
						printf(" ");
					printf("%d",i);
				}
				printf("\n");	
return 0;
}
