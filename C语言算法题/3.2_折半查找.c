#include<stdio.h>
int search(int a[],int n,int x);/*�Ե��õĺ�����������*/
void main()
{
	int i,x,z;       /*�Ա������ж���*/
	int a[10];
	printf("������10�����������\n");
	for(i=0;i<10;i++)
		scanf("%d",&a[i]);  /*����10�����������ֵ������a*/
	printf("��������Ҫ���ҵ���\n");
	scanf("%d",&x);        /*����Ҫ���ҵĹؼ��ֲ���ֵ��x*/
	z=search(a,10,x);      /*���ú���search()*/
	if(z)
		printf("��Ҫ���ҵ���%d�������е�λ���ǵ�%d��Ԫ��\n",x,z);
	else
		printf("��Ҫ���ҵ���%d���������У�\n");
}
int search(int a[],int n,int x)  /*��������search()*/
{
	int low,mid,high;/*�������*/
	low=0;           /*����������ֵ*/
	high=n-1;
	while(low<=high)  /*�۰����*/
	{
		mid=(low+high)/2;
		if(a[mid]==x)
			return mid+1;
		else if(a[mid]>x)
			high=mid-1;
		else low=mid+1;
	}
	return 0;
}