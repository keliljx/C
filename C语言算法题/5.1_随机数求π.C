#include<stdio.h>
#include<math.h>
#include<time.h>
#include<stdlib.h>
#include<graphics.h>
double rnd(int x)
{
 FILE *fp;
 time_t t1;
 static double a=262147.0,t,i,b=34359738365.0/549755813888.0;
 if(x==1)					/*得到一个新的随机数*/
 b=b*a-(long)(b*a);
 else
 {
   if((fp=fopen("rnd","rb+"))==NULL)
   {
    printf("cannot open this file\n");
    exit(0);
   }
   if(x==-1)				/*从磁盘文件rnd中读取上次的随机数，计算新的随机数*/
	   fread(&b,8,1,fp);
   else						/*x==0时，向磁盘文件中写入最后一次的随机数*/
   {
    rewind(fp);				/*使位置指针重新返回文件的开头*/
	fwrite(&b,8,1,fp);
   }
 }
 return(b);
}
main()
{
	int driver=VGA,mode=VGAHI;
	long i,m=0,n=1000000;
	float x,y;
	rnd(-1);							/*从磁盘中读取上一个随机数*/
	printf("\t\tget pai:");
	printf("\t\tpress any key");
	getch();
	initgraph(&driver,&mode,"");/*初始化图形模式*/
	settextstyle(DEFAULT_FONT,HORIZ_DIR,1);/*设置当前文本形式*/
	setlinestyle(0,0,1);					/*设定线型*/
	setbkcolor(15);							/*设置屏幕背景颜色*/
	setcolor(1);							/*设置当前画笔颜色*/
	cleardevice();							/*清屏*/
	line(55,450,558,450);					/*画直线*/
	line(553,445,558,450);
	line(553,455,558,450);
	outtextxy(452,448,"|");					/*在屏幕坐标像素点处显示一个字符串*/
	outtextxy(45,458,"0");
	outtextxy(455,458,"1");
	outtextxy(540,458,"x");
	line(55,450,55,30);
	line(55,30,50,35);
	line(55,30,60,35);
	outtextxy(50,47,"-");
	outtextxy(35,47,"1");
	outtextxy(35,30,"y");
	rectangle(55,50,455,450);				/*绘制矩形*/
	ellipse(55,450,0,90,400,400);			/*绘制弧线*/
	for(i=1;i<=n;i++)
	{
		x=rnd(1);							/*得到新的随机数*/
		y=rnd(1);
		if(x*x+y*y<=1)
		{
			m++;
			putpixel(55+400*x,450-400*y,4);	/*绘制像素点*/
		}
		else
			putpixel(55+400*x,450-400*y,2);
	}
	printf("\t\tpai=%f",4.0*m/n);
	getch();
	cleardevice();
	rnd(0);									/*将最后一个随机数存盘*/
}