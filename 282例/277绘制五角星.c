#include <graphics.h>
#include <math.h>
main()
{
    int i, j = 0, gdriver, gmode, points[20];
    gdriver = DETECT;
    initgraph(&gdriver, &gmode, "");								/*ͼ�η�ʽ��ʼ��*/
    setcolor(YELLOW);										/*���û�ͼ��ɫ*/
    setlinestyle(0, 0, 1);										/*��������*/
    for (i = 0; i < 5; i++)
    {
        points[j++] = (int)(320+150 * cos(0.4 *3.1415926 * i));			/*�������Ȧ��ĺ��������������*/
        points[j++] = (int)(240-150 * sin(0.4 *3.1415926 * i));			/*�������Ȧ������������������*/
        points[j++] = (int)(320+50 * cos(0.4 *3.1415926 * i + 0.6283));		/*�������Ȧ��ĺ��������������*/
        points[j++] = (int)(240-50 * sin(0.4 *3.1415926 * i + 0.6283));		/*�������Ȧ������������������*/
    }
    setfillstyle(1, RED);										/*������䷽ʽ*/
    fillpoly(10, points);										/*������ǽ������*/
    getch();
    closegraph();											/*�˳�ͼ��״̬*/
}
