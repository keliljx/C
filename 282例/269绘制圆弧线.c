#include <graphics.h>
main()
{
    int gdriver, gmode;
    gdriver = DETECT;
    initgraph(&gdriver, &gmode, "");						/*ͼ�η�ʽ��ʼ��*/
    setbkcolor(GREEN);								/*���ñ�����ɫΪ��ɫ*/
    setcolor(RED);									/*���û�ͼ��ɫΪ��ɫ*/
    arc(getmaxx() / 2, getmaxy() / 2, 0, 120, 100);				/*��Բ��*/
    getch();
    closegraph();									/*�˳�ͼ��״̬*/
}
