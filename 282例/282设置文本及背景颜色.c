#include<conio.h>
main()
{
    void *buf;
    clrscr();											/*����ַ���Ļ*/
    gotoxy(35,15);										/*��궨λ����35��15��*/
    textcolor(YELLOW);									/*�����ı���ɫΪ��ɫ*/
    textbackground(BLUE);									/*���ñ�����ɫΪ��ɫ*/
    cprintf("hello world\n");									/*����ַ���hello world*/
    cprintf("hello computer\n");								/*����ַ���hello computer*/
    buf=(char *)malloc(2*11*2);								/*bufָ�������ڴ�ռ�*/
    gettext(35,15,60,16,buf);								/*����ָ����Χ�ڵ��ı����ڴ���*/
    puttext(20,5,45,6,buf);									/*�����ڴ��б�����ı����*��ָ��λ��*/
    gotoxy(30,10);										/*��궨λ����30��10��*/
    textattr(RED|128|GREEN*16);							/*��textattr�����ı�����*/
    cprintf("Moring");										/*����ַ���Morning*/
  }
