#include <graphics.h>
main()
{
    int gdriver, gmode;
    gdriver = DETECT;
    initgraph(&gdriver, &gmode, "");					/*ͼ�η�ʽ��ʼ��*/
    ellipse(200, 200, 0, 360, 50, 100);					/*�ԣ�200��200��Ϊ���ĵ���Բ*/
    getch();
    closegraph();								/*�˳�ͼ��״̬*/
}
