#include<stdlib.h>
#include<graphics.h>
#include<math.h>
#include<stdio.h>
#include<time.h>
float distance(float x1,float y1,float x2,float y2)/*����������*/
{
	float l;
	l=sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
	return l;
}
/*��������������Բ��Բ��*/
float centre(float x1,float y1,float x2,float y2,float x3,float y3,float *m,float *n)
{
	float t,a,b,c,p1,p2,p3,q1,q2,q3,cos;
	a=distance(x1,y1,x2,y2);/*�������εı߳�*/
	b=distance(x2,y2,x3,y3);
	c=distance(x1,y1,x3,y3);
	if(a<b)					/*����߸���a*/
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
	cos=(b*b+c*c-a*a)/2*b*c;	/*�������Ӧ�ǵ�����ֵ*/
	if(cos<0)					/*�۽Ƿ���0*/
		return 0;
	p1=2*(x2-x1);
	p2=2*(y2-y1);
	p3=x2*x2-x1*x1+y2*y2-y1*y1;
	q1=2*(x3-x1);
	q2=2*(y3-y1);
	q3=x3*x3-x1*x1+y3*y3-y1*y1;
	*m=(p3*q2-p2*q3)/(p1*q2-p2*q1);	/*Բ�ĵ�ָ��*/
	*n=(p1*q3-p3*q1)/(p1*q2-p2*q1);
	return distance(x1,y1,*m,*n);	/*������������εİ뾶*/

}
double rnd(int x)
{
 FILE *fp;
 time_t t1;
 static double a=262147.0,b=34359738365.0/549755813888.0;
 if(x==1)					/*�õ�һ���µ������*/
 b=b*a-(long)(b*a);
 else
 {
   if((fp=fopen("rnd","rb+"))==NULL)
   {
    printf("cannot open this file\n");
    exit(0);
   }
   if(x==-1)				/*�Ӵ����ļ�rnd�ж�ȡ�ϴε�������������µ������*/
	   fread(&b,8,1,fp);
   else						/*x==0ʱ��������ļ���д�����һ�ε������*/
   {
    rewind(fp);				/*ʹλ��ָ�����·����ļ��Ŀ�ͷ*/
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
	printf("\t\tinput the point number n=");		/*��ʾ�����������*/
	scanf("%d",&n);
	initgraph(&driver,&mode,"");					/*ͼ��ģʽ��ʼ��*/
	settextstyle(DEFAULT_FONT,HORIZ_DIR,1);			/*�����ı���ʽ*/
	setlinestyle(0,0,1);
	setbkcolor(1);
	setcolor(15);
	cleardevice();
	line(55,450,638,450);							/*���ƺ�����*/
	line(633,445,638,450);
	line(633,455,638,450);
	for(i=0;i<=500;i+=100)							/*���ƺ�������ʾ�ı��*/
	{
		outtextxy(i+150,448,"|");
		outtextxy(i+45,458,itoa(i,w,10));
	}
	line(54,450,54,30);								/*����������*/
	line(54,30,49,35);
	line(54,30,59,35);
	for(i=100;i<=400;i+=100)						/*������������ʾ�ı��*/
	{
		outtextxy(51,448-i,"-");
		outtextxy(20,448-i,itoa(i,w,10));
	}
	for(i=1;i<=n;i++)								/*����������ص�*/
	{
		a[i][0]=rnd(1)*400+100;
		a[i][1]=rnd(1)*320+50;
		putpixel(55+a[i][0],450-a[i][1],15);
	}
	printf("\t\tpress any key to draw circularity!\n");	/*��ʾ���������ʼ������СԲ*/
	getch();
	setcolor(14);
	r0=0;
	for(i=1;i<=n-1;i++)									/*�����������������һ�룬ѡ�������*/
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
		x0=(a[i0][0]+a[j0][0])/2.0;						/*��������߶ε��е������*/
		y0=(a[i0][1]+a[j0][1])/2.0;						/*��������߶ε��е�������*/
		for(i=1;i<=n;i++)								/*�ж��е㵽�����ľ���*/
		{
			if(i==i0||i==j0) continue;
			if(distance(a[i][0],a[i][1],x0,y0)>r0) goto F1;/*�����������߶ε�һ�룬����תִ��F1*/
		}
	x0=x0+55;												/*��СԲ��Բ�ĺ�����*/
	y0=450-y0;												/*��СԲ��ԭ��������*/
	goto F2;												/*��תִ��F2*/
F1:	r3=0,r0=0;
	for(i=1;i<=n-2;i++)
		for(j=i+1;j<=n-1;j++)
			for(k=j+1;k<=n;k++)								
			{												/*�������������Բ��Բ������Ͱ뾶*/
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
   line(x0,y0,a[j0][0]+55,450-a[j0][1]);					/*���ư뾶�߶�*/
   printf("\t\tthe centre of a circle(%7.2f,%7.2f),r=%7.2f\n",x0,y0,r0);
   for(i=1;i<=n;i++)										/*���»���������ص�*/
	   putpixel(55+a[i][0],450-a[i][1],10);
   getch();
   cleardevice();
   rnd(0);
}
