#include <dos.h>
#include <stdio.h>
main()
{
	struct date setd,now; 										/*����setdΪdate�ṹ�����*/
	struct date origind; 										/*����origindΪdate�ṹ�����*/
	getdate(&origind); 											/*��ȡϵͳ��ǰ����*/
	printf("original data is:%d--%d--%d\n", origind.da_year, origind.da_mon,origind.da_day);	/*���ϵͳ��ǰ����*/
	setd.da_year = 2008; 										/*����ϵͳ���������Ϊ2008*/
	setd.da_mon = 10;											/*����ϵͳ�������·�Ϊ10*/
	setd.da_day = 23;											/*����ϵͳ��������Ϊ23*/
	setdate(&setd); 								/*ʹ��setdate()��������ָ�������ݶ�ϵͳʱ���������*/
	getdate(&now);											/*��ȡϵͳ�������ú�ĵ�ǰ����*/
	printf("date after setting is:%d--%d--%d", now.da_year, now.da_mon,now.da_day);	/*������ú��ϵͳʱ��*/
	getch();
}
