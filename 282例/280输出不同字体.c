#include <stdio.h>
#include <graphics.h>
#include <time.h>
int main()
{
    int i, gdriver, gmode;
    time_t curtime;
    char s[30];
    gdriver = DETECT;
    time(&curtime);
    initgraph(&gdriver, &gmode, "");						/*ͼ�η�ʽ��ʼ��*/
    setbkcolor(BLUE);								/*������Ļ������ɫΪ��ɫ*/
    cleardevice();									/*����*/
    setviewport(100, 100, 580, 380, 1);						/*�趨ͼ�δ���*/
    setfillstyle(1, 2);									/*����������ͼ���ɫ*/
    setcolor(15);										/*���û�ͼ��ɫΪ��ɫ*/
    rectangle(0, 0, 480, 280);							/*�����ο�*/
    floodfill(50, 50, 15);								/*��ָ������������*/
    setcolor(12);										/*���û�ͼ��ɫΪ����ɫ*/
    settextstyle(1, 0, 7);								/*��������ַ����Ρ����򼰴�С*/
    outtextxy(20, 20, "Hello China");						/*�ڹ涨λ������ַ���*/
    setcolor(15);										/*���û�ͼ��ɫΪ��ɫ*/
    settextstyle(3, 0, 6);								/*��������ַ����Ρ����򼰴�С*/
    outtextxy(120, 85, "Hello China");						/*�ڹ涨λ������ַ���*/
    setcolor(14);										/*���û�ͼ��ɫΪ��ɫ*/
    settextstyle(2, 0, 8);
    sprintf(s, "Now is %s", ctime(&curtime));					/*ʹ�ø�ʽ���������*/
    outtextxy(20, 150, s);								/*��ָ��λ�ý�s����Ӧ�ĺ������*/
    setcolor(1);										/*������ɫΪ��ɫ*/
    settextstyle(4, 0, 3);								/*��������ַ����Ρ����򼰴�С*/
    outtextxy(50, 220, s);								/*�ڹ涨λ������ַ���*/
    getch();
    exit(0);
}
