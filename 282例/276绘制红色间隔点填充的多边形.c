#include <graphics.h>
void main()
{
    int gdriver, gmode, n;
    int points[] =
    {
        200, 200, 150, 250, 150, 300, 200, 350, 250, 350, 300, 300, 300, 250,
            250, 200
    };														/*���������Ŷ�������*/
    gdriver = DETECT;
    initgraph(&gdriver, &gmode, "");									/*ͼ�η�ʽ��ʼ��*/
    setfillstyle(INTERLEAVE_FILL, RED);								/*������䷽ʽ*/
    n = sizeof(points) / (2 *sizeof(int));									/*���㶨�����*/
    fillpoly(n, points);												/*�Զ���ν������*/
    getch();
    closegraph();												/*�˳�ͼ��״̬*/
}
