#include<stdio.h>
float *search(float(*p)[4])
{
	int i;											/*��������*/
	float *pt;											/*����ָ�����*/
	pt = *(p + 1);										/*��ȡ��һ�е��׵�ַ*/
	for(i=0;i<4;i++)
	{
		if(*(*p+i)<60)									/*�жϷ����Ƿ�С��60*/
		{
			pt=*p;									/*ָ�����׵�ַ*/
		}
	}
	return (pt);										/*�����׵�ַ*/
}
void main()
{
	float score[][4]={{60,75,82,91},{75,81,91,90},{51,65,78,84},{65,72,78,72}};		/*��������*/
	float *p;												/*����ָ�����*/
	int i, j;												/*������������*/
	for(i=0;i<4;i++)
	{
		p=search(score+i);									/*�����в��������*/
		if (p==*(score+i))
		{
			printf("The student NO.%d list:",i+1);
			for (j=0;j<4;j++,p++)							/*����ɼ�*/
			{
				printf("%5.1f",*p);
			}
		}
	}
	getch();
}
