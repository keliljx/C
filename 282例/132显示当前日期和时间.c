#include <dos.h>
#include <stdio.h>
main()
{
	struct date d; 														/*����date�ṹ�����ͱ���d*/
	struct time t; 														/*����time�ṹ�����ͱ���t*/
	getdate(&d); 														/*��ȡϵͳ��ǰ����*/
	gettime(&t); 														/*��ȡϵͳ��ǰʱ��*/
	printf("the current day is:%d--%d--%d\n",d.da_year, d.da_mon, d.da_day);		/*��ָ����ʽ�����ǰ����*/
	printf("the current time is:%d:%d:%d", t.ti_hour, t.ti_min, t.ti_sec);			/*��ָ����ʽ�����ǰʱ��*/
	getch();
}
