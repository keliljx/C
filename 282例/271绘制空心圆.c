#include <graphics.h>
main()
{
    int gdriver, gmode;
    gdriver = DETECT;
    initgraph(&gdriver, &gmode, "");							/*ͼ�η�ʽ��ʼ��*/
    setbkcolor(WHITE);									/*���ñ���ɫΪ��ɫ*/
    setcolor(RED);										/*���û�ͼɫΪ��ɫ*/
    circle(getmaxx() / 2, getmaxy() / 2, 100);						/*��Բ*/
    getch();
    closegraph();										/*�˳�ͼ��״̬*/
}
