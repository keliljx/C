#include <time.h>
#include <stdio.h>
#include <dos.h>
main()
{
	time_t start, end; 									/*����time_t���ͱ���start��end*/
	start = time(NULL); 								/*����ǰʱ�丳��start*/
	sleep(10); 										/*�����ж�10����*/
	end = time(NULL); 								/*���жϺ�ĵ�ǰʱ�丳��end*/
	printf("runtime is:%f(s)\n", difftime(end, start));		/*����difftime��������start��end˵������ʱ��*/
	getch();
	return 0;
}
