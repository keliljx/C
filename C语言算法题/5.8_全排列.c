#include<stdio.h>
#define max 100
quan(int a[],int n,int s,int r[],int m)
{
	int i,j,k,flag=0;
	int b[max];
	for(i=0;i<n;i++)
	{
		flag=1;
		r[s]=a[i];					/*�̶�����������*/
		j=0;
		for(k=0;k<n;k++)			/*����λ�ã�������������и���b������*/
			if(i!=k)
			{
				b[j]=a[k];
				j++;
			}
		quan(b,n-1,s+1,r,m);		/*�ݹ����ȫ���к���*/		
	}
	if(flag==0)						/*�õ�һ��������*/
	{
		for(k=0;k<m;k++)			
			printf("%d ",r[k]);		/*���������н��������r�е�����*/
		printf("\n");
	}
}
main()
{
	int a[max],r[max];
	int i,n;
	printf("����Ԫ�ظ�����");
	scanf("%d",&n);
	printf("������һ���������У�\n");
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);
	printf("���������������з�ʽ��\n");
	quan(a,n,0,r,n);				/*����ȫ����*/
	getche();
}