#include <graphics.h>
#include <stdlib.h>
#include <conio.h>
void main()
{
    int gdriver, gmode;
    unsigned size;
    void *buf;
    gdriver = DETECT;
    initgraph(&gdriver, &gmode, "");								/*ͼ�ν����ʼ��*/
    setcolor(15);												/*���û�ͼ��ɫΪ��ɫ*/
    rectangle(20, 20, 200, 200);									/*��������*/
    setcolor(RED);											/*���û�ͼ��ɫΪ��ɫ*/
    line(20, 20, 200, 200);										/*���Խ���*/
    setcolor(GREEN);											/*���û�ͼ��ɫΪ��ɫ*/
    line(20, 200, 200, 20);
    outtext("press any key,you can see the same image!!");
    getch();
    size = imagesize(20, 20, 200, 200);								/*�������ͼ��洢�����ֽ���*/
    if (size !=  - 1)
    {
        buf = malloc(size);										/*bufָ�����ڴ��з���Ŀռ�*/
        if (buf)
        {
            getimage(20, 20, 200, 200, buf);							/*����ͼ��bufָ����ڴ�ռ�*/
            putimage(100, 100, buf, COPY_PUT);						/*�������ͼ�������ָ��λ��*/
            putimage(300, 50, buf, COPY_PUT);
            putimage(400, 150, buf, COPY_PUT);
        }
    }
    getch();
    closegraph();											/*�˳�ͼ��״̬*/
}
