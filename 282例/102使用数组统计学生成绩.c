#include<stdio.h>
#define MAX 50												/*����MAXΪ����50*/
main()
{
	int i,num;													/*�������i��numΪ��������*/
	int Chinese[MAX],Math[MAX],English[MAX];				/*��������Ϊ��������*/
	long StudentID[MAX];										/*����StudentIDΪ������*/
	float average[MAX];
	printf("please input the number of students");
	scanf("%d",&num);										/*����ѧ����*/
	printf("Please input a StudentID and three scores:\n");
	printf("    StudentID  Chinese  Math    English\n");
	for( i=0; i<num; i++ )										/*���������ѧ����������ѭ������*/
	{
		printf("No.%d>",i+1);
		scanf("%ld%d%d%d",&StudentID[i],&Chinese[i],&Math[i],&English[i]);
		/*��������ѧ�ż����ģ���ѧ��Ӣ��ɼ�*/
		average[i] = (float)(Chinese[i]+Math[i]+English[i])/3;		/*�����ƽ���ɼ�*/
	}
	puts("\nStudentNum    Chinese   Math   English  Average");
	for( i=0; i<num; i++ )										/*forѭ����ÿ��ѧ���ĳɼ���Ϣ���*/
	{
		printf("%8ld %8d %8d %8d %8.2f\n",StudentID[i],Chinese[i],Math[i],English[i],average[i]);
	}
	return 0;
}
