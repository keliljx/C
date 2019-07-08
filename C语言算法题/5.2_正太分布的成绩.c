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

double grade(double m,double f)
{
	double s=0.0,i,t;
	for(i=1;i<=12;i++)
		s+=rnd(1);
	t=f*(s-6.0)+m;
	return t;
}
main()
{
	long s=0;
	static int a[151],i,g,k=10000,max=0,min=150;
	int driver=VGA,mode=VGAHI;
	char *w="";
	rnd(-1);								/*读取上次的随机数*/
	printf("\tsimulate the grade of 10000 students in senior high school,0-150\n\n");
	for(i=1;i<=k;i++)
	{
		g=(int)(grade(81.0,25.0));		/*将随机数强制转换为整数*/
		if(g>150) g=150;
		if(g<0) g=0;
		if(g>max) max=g;
		if(g<min) min=g;
		s+=g;
		a[g]++;
	}
	for(g=0;g<=150;g++)
		printf("%6d:%3d",g,a[g]);
	printf("\n\taverage:%6.2f\thigh:%3d\tlow:%3d\n\n",1.0*s/k,max,min);
	printf("press any key to print!");getch();
	initgraph(&driver,&mode,"");
	settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
	setlinestyle(0,0,1);
	setbkcolor(15);
	setcolor(1);
	cleardevice();
	line(30,430,638,430);
	line(633,425,638,430);
	line(633,435,638,430);
	for(i=0;i<=150;i+=10)
	{
		outtextxy(i*4+58,428,"|");
		outtextxy(i*4+10,438,itoa(i,w,10));
	}
	line(30,430,30,30);
	line(30,30,35,35);
	line(30,30,25,35);
	for(i=10;i<=250;i+=10)
	{
		outtextxy(28,428-i*3/2+0.5,"-");
		outtextxy(2,428-i*3/2,itoa(i,w,10));
	}
	setcolor(RED);
	for(i=0;i<150;i++)
		line(i*4+30,430,i*4+30,430-a[i]*3/2);
	getch();
	cleardevice();
	rnd(0);
}