#include<graphics.h>
main()
{int gdriver,gmode,i,j;
/*cleardevice();							*/
gdriver=DETECT;
initgraph(&gdriver,&gmode,"");					/*��ʼ��ͼ�ν���*/
for(i=120;i<=400;i=i+40)					/*������ʼ��120����ֹ��400�������40*/
for(j=120;j<=400;j++)
{
putpixel(i,j,YELLOW);						/*����*/
putpixel(j,i,YELLOW);
}
getch();
closegraph();							/*�˳�ͼ�ν���*/
}