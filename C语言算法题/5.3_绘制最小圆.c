#include<stdlib.h>
#include<graphics.h>
#include<math.h>
#include<stdio.h>
#include<time.h>
float distance(float x1,float y1,float x2,float y2)/*求两点间距离*/
{
	float l;
	l=sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
	return l;
}
/*求锐角三角形外接圆的圆心*/
float centre(float x1,float y1,float x2,float y2,float x3,float y3,float *m,float *n)
{
	float t,a,b,c,p1,p2,p3,q1,q2,q3,cos;
	a=distance(x1,y1,x2,y2);/*求三角形的边长*/
	b=distance(x2,y2,x3,y3);
	c=distance(x1,y1,x3,y3);
	if(a<b)					/*将最长边赋给a*/
	{
		t=a;
		a=b;
		b=t;
	}
	if(a<c)
	{
		t=a;
		a=c;
		c=t;
	}
	cos=(b*b+c*c-a*a)/2*b*c;	/*最长边所对应角的余弦值*/
	if(cos<0)					/*钝角返回0*/
		return 0;
	p1=2*(x2-x1);
	p2=2*(y2-y1);
	p3=x2*x2-x1*x1+y2*y2-y1*y1;
	q1=2*(x3-x1);
	q2=2*(y3-y1);
	q3=x3*x3-x1*x1+y3*y3-y1*y1;
	*m=(p3*q2-p2*q3)/(p1*q2-p2*q1);	/*圆心的指针*/
	*n=(p1*q3-p3*q1)/(p1*q2-p2*q1);
	return distance(x1,y1,*m,*n);	/*返回锐角三角形的半径*/

}
double rnd(int x)
{
 FILE *fp;
 time_t t1;
 static double a=262147.0,b=34359738365.0/549755813888.0;
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
	int driver=VGA,mode=VGAHI,n=0,i,i0,j,j0,k,k0;
	char *w="";
	float a[1000][2],r0,r2,r3,x0,y0,x1,y1,x2,y2,x3,y3,*px=&x1,*py=&y1;
	rnd(-1);
	printf("\t\tthe minimal circle\n\n");		
	printf("\t\tinput the point number n=");		/*提示输入随机点数*/
	scanf("%d",&n);
	initgraph(&driver,&mode,"");					/*图形模式初始化*/
	settextstyle(DEFAULT_FONT,HORIZ_DIR,1);			/*设置文本样式*/
	setlinestyle(0,0,1);
	setbkcolor(1);
	setcolor(15);
	cleardevice();
	line(55,450,638,450);							/*绘制横坐标*/
	line(633,445,638,450);
	line(633,455,638,450);
	for(i=0;i<=500;i+=100)							/*绘制横坐标显示的标度*/
	{
		outtextxy(i+150,448,"|");
		outtextxy(i+45,458,itoa(i,w,10));
	}
	line(54,450,54,30);								/*绘制纵坐标*/
	line(54,30,49,35);
	line(54,30,59,35);
	for(i=100;i<=400;i+=100)						/*绘制纵坐标显示的标度*/
	{
		outtextxy(51,448-i,"-");
		outtextxy(20,448-i,itoa(i,w,10));
	}
	for(i=1;i<=n;i++)								/*绘制随机像素点*/
	{
		a[i][0]=rnd(1)*400+100;
		a[i][1]=rnd(1)*320+50;
		putpixel(55+a[i][0],450-a[i][1],15);
	}
	printf("\t\tpress any key to draw circularity!\n");	/*提示按任意键开始绘制最小圆*/
	getch();
	setcolor(14);
	r0=0;
	for(i=1;i<=n-1;i++)									/*计算任意两点间距离的一半，选距离最长的*/
		for(j=i+1;j<=n;j++)
		{
			r2=distance(a[i][0],a[i][1],a[j][0],a[j][1])/2.0;
			if(r2>r0)
			{
				r0=r2;
				i0=i;
				j0=j;
			}
		}
		x0=(a[i0][0]+a[j0][0])/2.0;						/*距离最长的线段的中点横坐标*/
		y0=(a[i0][1]+a[j0][1])/2.0;						/*距离最长的线段的中点纵坐标*/
		for(i=1;i<=n;i++)								/*判断中点到任意点的距离*/
		{
			if(i==i0||i==j0) continue;
			if(distance(a[i][0],a[i][1],x0,y0)>r0) goto F1;/*若距离大于最长线段的一半，则跳转执行F1*/
		}
	x0=x0+55;												/*最小圆的圆心横坐标*/
	y0=450-y0;												/*最小圆的原型纵坐标*/
	goto F2;												/*跳转执行F2*/
F1:	r3=0,r0=0;
	for(i=1;i<=n-2;i++)
		for(j=i+1;j<=n-1;j++)
			for(k=j+1;k<=n;k++)								
			{												/*计算三角形外接圆的圆心坐标和半径*/
				r3=centre(a[i][0],a[i][1],a[j][0],a[j][1],a[k][0],a[k][1],px,py);
				if(r3!=0&&r3>r0)
				{
					i0=i;j0=j;k0=k;x0=*px;y0=*py;r0=r3;
				}

			}
	x0=x0+55;y0=450-y0;
F2:circle(x0,y0,r0);
   setcolor(15);
   circle(x0,y0,2);
   setcolor(12);
   line(x0,y0,a[j0][0]+55,450-a[j0][1]);					/*绘制半径线段*/
   printf("\t\tthe centre of a circle(%7.2f,%7.2f),r=%7.2f\n",x0,y0,r0);
   for(i=1;i<=n;i++)										/*重新绘制随机像素点*/
	   putpixel(55+a[i][0],450-a[i][1],10);
   getch();
   cleardevice();
   rnd(0);
}
