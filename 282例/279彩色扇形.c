#include <graphics.h>
void main()
{
    int gdriver, gmode;
    int i, start, end;										/*���ñ���Ϊ��������*/
    gdriver = DETECT;
    initgraph(&gdriver, gmode, "");							/*ͼ�η�ʽ��ʼ��*/
    start = 0;											/*start����ֵΪ0��*/
    end = 45;											/*end����ֵΪ45��*/
    for (i = 0; i < 8; i++)
    {
        setfillstyle(SOLID_FILL, i);							/*������䷽ʽ*/
        pieslice(getmaxx() / 2, getmaxy() / 2, start, end, 200);		/*������*/
        start += 45;										/*��ʼ�Ƕ���ÿ������45��*/
        end += 45;										/*��ֹ�Ƕ���ÿ������45��*/
    }
    getch();
    closegraph();										/*�˳�ͼ��״̬*/
}
