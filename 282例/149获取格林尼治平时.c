#include<stdio.h>
#include<time.h>
main() 
{
	struct tm * gmtp;												//tm�ṹָ��
	time_t secs;													//����time_t���ͱ���secs
	time(&secs);													//��ȡʱ��
	gmtp=gmtime(&secs);											//��ȡ��������ƽʱ
	printf("\nGreenwich time: %d-%d-%d %d:%d:%d\n ",gmtp->tm_mon,	//�����������ƽʱ
	gmtp->tm_mday,gmtp->tm_year+1900,gmtp->tm_hour,gmtp->tm_min,gmtp->tm_sec);
}
