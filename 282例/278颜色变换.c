#include <graphics.h>
void main(void)
{
    int color;											/*�������colorΪ��������*/
    int gdriver, gmode;
    gdriver = DETECT;
    initgraph(&gdriver, &gmode, "");							/*ͼ�η�ʽ��ʼ��*/
    for (color = 0; color <= 14; color++)
    {
        setbkcolor(color);									/*���ñ�����ɫ*/
        getch();
    }
    closegraph();
}
