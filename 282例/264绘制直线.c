#include<graphics.h>						/*ͷ�ļ�Ϊgraphics.h*/
main()
{int gdriver=DETECT,gmode;
initgraph(&gdriver,&gmode,"");					/*ʹ��initgraph��������ͼ�γ�ʼ��*/
line(100,300,300,300);						/*ʹ��line����������*/
moveto(350,50);							/*�ƶ��α굽��350��50����*/
linerel(0,300); 						/*ʹ��linerel����������*/
lineto(200,200);						/*ʹ��lineto������б��*/
getch();
closegraph();							/*�˳�ͼ��״̬*/
}