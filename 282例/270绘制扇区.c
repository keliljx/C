#include <graphics.h>
main()
{
    int gdriver, gmode;
    gdriver = DETECT;
    initgraph(&gdriver, &gmode, ""); /*ͼ�η�ʽ��ʼ��*/
    pieslice(260, 200, 0, 120, 100); /*������*/
    getch();
    closegraph(); /*�˳�ͼ��״̬*/
}
