#include <graphics.h>
main()
{
    int gdriver, gmode;
    gdriver = DETECT;
    initgraph(&gdriver, &gmode, "");							/*ͼ�η�ʽ��ʼ��*/
    setcolor(RED);										/*������ͼ��ɫ*/
    setlinestyle(DASHED_LINE, 0, 3);							/*�����ߵĿ�Ⱥ���ʽ*/
    rectangle(100, 100, 550, 350);								/*������*/
    getch();
    closegraph();										/*�˳�ͼ��״̬*/
}
