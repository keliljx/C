#include<stdio.h>
float average(float array[],int n)							/*�Զ�����ƽ����ߺ���*/
{
	int i;
	float aver,sum=0;
	for(i=0;i<n;i++)
	sum+=array[i];									/*��for���ʵ��sum�ۼ����*/
	aver=sum/n;										/*�ܺͳ����������ƽ��ֵ*/
	return(aver);										/*����ƽ��ֵ*/
}
int main()
{
	float average(float array[],int n);						/*��������*/
	float height[100],aver;
	int i,n;
	printf("������ѧ��������:\n");
	scanf("%d",&n);									/*����ѧ������*/
	printf("������ѧ���ǵ����:\n");
	for(i=0;i<n;i++)
	scanf("%f",&height[i]);								/*�������ѧ�������*/
	printf("\n");
	aver=average(height,n);								/*����average�������ƽ�����*/
	printf("ѧ����ƽ�����Ϊ��%6.2f\n",aver);			/*��ƽ��������*/
	return 0;
}
