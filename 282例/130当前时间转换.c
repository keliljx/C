#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include<conio.h>
main()
{
	time_t Time; 									/*����TimeΪtime_t����*/
	struct tm *t,  *gt; 								/*����ָ��t��gtΪtm�ṹ����*/
	Time = time(NULL); 							/*��time��������ֵ�浽Time��*/
	t = localtime(&Time); 							/*����localtime����*/
	printf("Local time is:%s", asctime(t));				/*����asctime�������Թ̶���ʽ�����ǰʱ��*/
	gt = gmtime(&Time); 							/*����gmtime����������ǰʱ��ת��Ϊ��������ʱ��*/
	printf("Greenwich Time is:%s", asctime(gt));		/*����asctime�������Թ̶���ʽ�����������ʱ��*/
	getch();
	return 0;
}
