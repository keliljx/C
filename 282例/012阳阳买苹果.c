#include <stdio.h>
main()
{
	int n=2,day=0;								/*����n��dayΪ��������*/
	float money=0,ave;							/*����money��aveΪ��������*/
	while(n<100)								/*ƻ������������100����while�б��ʽnС��100*/
	{
		money+=0.8*n;						/*��ÿ�컨��Ǯ���ۼ����*/
		day++;								/*�����Լ�*/
		n*=2;								/*ÿ����ǰһ�������2��*/
	}
	ave=money/day;							/*���ƽ��ÿ�컨��Ǯ��*/
	printf("The result is %.6f\n",ave);				/*�������ave���*/
}
