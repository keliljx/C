#include <stdio.h>
#include <stdlib.h>
#include <time.h>
main()
{
	time_t Time;									/*����TimeΪtime_t����*/
	struct tm *t;									/*����ָ��tΪtm�ṹ����*/
	Time = time(NULL);							/*��time��������ֵ�浽Time��*/
	t = localtime(&Time);							/*����localtime����*/
	printf("Local time is:%s", asctime(t));				/*����asctime�������Թ̶���ʽ�����ǰʱ��*/
	getch();
	return 0;
}
