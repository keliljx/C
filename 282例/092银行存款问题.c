#include <stdio.h>
void main()
{
	int i;												/*�������ͱ���*/
	float total=0;										/*����ʵ�ͱ���������ʼ��*/
	for(i=0;i<5;i++)									/*ѭ��*/
		total=(total+1000)/(1+0.025);						/*�ۼƴ���*/
	printf("must save %5.2f at first. \n",total); 			/*�������*/
}
