#include <graphics.h>
int main()
{
    int gdriver, gmode, i;
    int point[16] =
    {
        200, 100, 300, 100, 300, 110, 330, 95, 300, 80, 300, 90, 200, 90, 200, 100
    };												/*�������������������point��*/
    gdriver = DETECT;
    initgraph(&gdriver, &gmode, "");							/*ͼ�η�ʽ��ʼ��*/
    setbkcolor(BLUE);									/*���ñ�����ɫΪ��ɫ*/
    cleardevice();										/*����*/
    setcolor(WHITE);										/*������ͼ��ɫ*/
    drawpoly(8, point);									/*��һ��ͷ*/
    getch();
    closegraph();
    return 0;
}
