#include <dos.h>
#include <stdio.h>
main()
{
	struct time sett, now; 								/*����sett,nowΪtime�ṹ�����*/
	struct time origint; 									/*����origintΪtime�ṹ�����*/
	gettime(&origint); 									/*��ȡϵͳ��ǰʱ��*/
	printf("original time is:%d:%d:%d\n",origint.ti_hour, origint.ti_min,origint.ti_sec);/*���ϵͳ��ǰʱ��*/
	sett.ti_hour = 10; 									/*����ϵͳʱ����СʱΪ10*/
	sett.ti_min = 5; 									/*����ϵͳʱ���з�Ϊ5*/
	sett.ti_sec = 12; 									/*����ϵͳʱ������Ϊ12*/
	sett.ti_hund = 32;
	settime(&sett); 									/*ʹ��settime()����ָ�������ݶ�ϵͳʱ���������*/
	gettime(&now);
	printf("time after setting is:%d:%d:%d",now.ti_hour, now.ti_min,now.ti_sec); 	/*������ú��ϵͳʱ��*/
	getch();
}
