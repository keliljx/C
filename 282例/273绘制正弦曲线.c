#include <conio.h>
#include <math.h>
#include <graphics.h>
main()
{
    int y = 200;
    int i, h;
    float m;
    int gdriver, gmode;
    gdriver = DETECT;
    initgraph(&gdriver, &gmode, "");							/*ͼ�η�ʽ��ʼ��*/
    setviewport(50, 50, 450, 450, 1);							/*�趨ͼ�δ���*/
    setcolor(14);											/*���û�ͼ��ɫΪ��ɫ*/
    rectangle(0, 0, 400, 400);								/*�����ο�*/
    line(200, 0, 200, 400);									/*����������*/
    line(0, 200, 400, 200);									/*����������*/
    for (i = 0; i < 400; i++)
    {
        m = 100 * sin(i / 31.83);								/*��ÿ�����ض�Ӧ��sinֵ*/
        h = y - (int)m;									/*���ÿ�����ص������������������λ��*/
        putpixel(i, h, 15);									/*����*/
        delay(10000);
    }
    getch();
    closegraph();										/*�˳�ͼ��״̬*/
} 
