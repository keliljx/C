#include <stdio.h>
#include<time.h>
main()
{
	time_t now;												//����time_t���ͱ���
	time(&now);												//��ȡ��ǰϵͳ������ʱ��
	printf("\nNow is:%s",ctime(&now));							//�����ǰϵͳ������ʱ��
}
