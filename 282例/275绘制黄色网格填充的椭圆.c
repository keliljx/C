#include <graphics.h>
main()
{
    int gdriver, gmode;
    gdriver = DETECT;
    initgraph(&gdriver, &gmode, "");						/*ͼ�η�ʽ��ʼ��*/
    setcolor(RED);									/*���û�ͼ��ɫΪ��ɫ*/
    ellipse(320, 240, 0, 360, 160, 80);						/*����Ļ���Ļ���һ��Բ*/
    setfillstyle(7, 14);									/*����������ͼ���ɫ*/
    floodfill(320, 240, RED);							/*����Բ�������*/
    getch();
    closegraph();									/*�˳�ͼ��״̬*/
}
