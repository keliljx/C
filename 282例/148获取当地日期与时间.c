#include<stdio.h>
#include<time.h>
main() 
{ 
	struct tm * tmpointer;											// tm�ṹָ��
	time_t secs;													//����time_t���ͱ���
	time(&secs);													//��ȡϵͳ������ʱ��
	tmpointer=localtime(&secs);										//��ȡ��������ʱ��
	//�������ʱ��
	printf("\nNow: %d-%d-%d %d:%d:%d\n ",tmpointer->tm_mon,tmpointer->
	tm_mday,tmpointer->tm_year+1900,tmpointer->tm_hour,tmpointer->tm_min,tmpointer->tm_sec);
}
